#!/usr/bin/env node

if (process.argv.length < 3) {
    console.log(`Usage: ${process.argv[0]} ${process.argv[1]} LeetcodeProblemURL`);
    process.exit();
}
const URL = process.argv[2];
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
    let probName = data[1];
    let dirpath = path.join(__dirname, "random", probNumber);
    if (!fs.existsSync(dirpath)) {
        fs.mkdirSync(dirpath, {
            recursive: true
        });
    }
    let readmePath = path.join(dirpath, "readme.md");
    let codePath = path.join(dirpath, "code.cc");
    fs.writeFile(readmePath, `# ${probNumber}. ${probName}\n\n[${URL}](${URL})\n\n`, (err) => {
        if (!err) return;
        console.error(`Writing ${readmePath} error...`);
        console.error(err);
    });
    fs.writeFile(codePath, "", (err) => {
        if (!err) return;
        console.error(`Writing ${codePath} error...`);
        console.error(err);
    });

    await browser.close();
})();

console.log(URL);