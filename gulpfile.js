const { src, dest, watch,series } = require('gulp');
const sass = require('gulp-sass')(require('sass'));
const postcss = require('gulp-postcss');
const autoprefixer = require('autoprefixer');
const cssnano = require('cssnano');
const browsersync = require('browser-sync').create();
const scssPath = 'Website/src/scss/**/*.scss';
const cssPath = 'Website/dist/css/';

function css(){
    return src(scssPath)
    .pipe(sass())
    .pipe(postcss([autoprefixer('last 2 versions'), cssnano()]))
    .pipe(dest(cssPath))
}

function browsersyncServe(cb){
    browsersync.init({
      server: {
        baseDir: '.'
      }
    });
    cb();
}


function browsersyncReload(cb){
    browsersync.reload();
    cb();
}

function watchTask(){
    watch('*.html', browsersyncReload);
    watch(scssPath, series(css, browsersyncReload));
  }


exports.default = series(
    css,
    browsersyncServe,
    watchTask
);