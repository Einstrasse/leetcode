#!/usr/bin/env node

if (process.argv.length < 3) {
    console.log(`Usage: ${process.argv[0]} ${process.argv[1]} LeetcodeProblemURL`);
    process.exit();
}
let sanitizeURL = (url) => {
    const suffix = "submissions/"
    if (url.endsWith(suffix)) {
        url = url.slice(0, -suffix.length);
    }
    return url;
}
const URL = sanitizeURL(process.argv[2]);
const puppeteer  = require('puppeteer');
const fs = require('fs');
const path = require('path');
(async () => {
    const browser = await puppeteer.launch({
        headless: true
    });
    const page = await browser.newPage();
    await page.goto(URL);
    let rawTitle = await page.$eval(
        ".css-v3d350", element => {
            return element.textContent;
        }
    );
    if (typeof rawTitle !== 'string' || rawTitle.indexOf(". ") === -1) {
        console.error("Cannot find title!")
        process.exit();
    }
    let data = rawTitle.split(". ");
    let probNumber = data[0].padStart(4, '0');
    console.log(`For Problem ${probNumber}....`);
    let probName = data[1];
    let dirpath = path.join(__dirname, "random", probNumber);
    if (!fs.existsSync(dirpath)) {
        fs.mkdirSync(dirpath, {
            recursive: true
        });
    }
    let readmePath = path.join(dirpath, "readme.md");
    let codePath = path.join(dirpath, "code.cc");
    fs.writeFile(readmePath, `# ${probNumber}. ${probName}\r\n\r\n[${URL}](${URL})    \r\n\r\n## My Solution\r\n\r\n\r\n### Time Complexity\r\n\r\n### Space Complexity\r\n\r\n## Better Solution\r\n`, (err) => {
        if (err) {
            console.error(`Writing ${readmePath} error...`);
            console.error(err);
        } else {
            console.log(`Writing ${readmePath} DONE!`);
        }
    });
    fs.writeFile(codePath, "", (err) => {
        if (err) {
            console.error(`Writing ${codePath} error...`);
            console.error(err);
        } else {
            console.log(`Writing ${codePath} DONE!`);
        }
    });

    await browser.close();
})();