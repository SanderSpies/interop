declare var NaN: number;
declare var Infinity: number;
declare var undefined: void;

declare function parseInt(string: mixed, radix?: number): number;
declare function parseFloat(string: mixed): number;
declare function isNaN(number: mixed): boolean;
declare function isFinite(number: mixed): boolean;
declare function decodeURI(encodedURI: string): string;
declare function decodeURIComponent(encodedURIComponent: string): string;
declare function encodeURI(uri: string): string;
declare function encodeURIComponent(uriComponent: string): string;

declare var console: {
  assert(condition: mixed, ...data: Array<any>): void;
  clear(): void;
  count(label: string): void;
  debug(...data: Array<any>): void;
  dir(...data: Array<any>): void;
  dirxml(...data: Array<any>): void;
  error(...data: Array<any>): void;
  exception(...data: Array<any>): void;
  group(...data: Array<any>): void;
  groupCollapsed(...data: Array<any>): void;
  groupEnd(): void;
  info(...data: Array<any>): void;
  log(...data: Array<any>): void;
  profile(name: string): void;
  profileEnd(): void;
  // table(tabularData: { [key: string]: any } | Array<{ [key: string]: any }> | Array<Array<any>>): void;
  time(label: string): void;
  timeEnd(label: string): void;
  timeStamp(label?: string): void;
  trace(...data: Array<any>): void;
  warn(...data: Array<any>): void;
};

declare var Math: {
  E: number;
  LN10: number;
  LN2: number;
  LOG10E: number;
  LOG2E: number;
  PI: number;
  SQRT1_2: number;
  SQRT2: number;
  abs(x: number): number;
  acos(x: number): number;
  acosh(x: number): number;
  asin(x: number): number;
  asinh(x: number): number;
  atan(x: number): number;
  atan2(y: number, x: number): number;
  atanh(x: number): number;
  cbrt(x: number): number;
  ceil(x: number): number;
  clz32(x: number): number;
  cos(x: number): number;
  cosh(x: number): number;
  exp(x: number): number;
  expm1(x: number): number;
  floor(x: number): number;
  fround(x: number): number;
  hypot(...values: Array<number>): number;
  imul(y: number, x: number): number;
  log(x: number): number;
  log10(x: number): number;
  log1p(x: number): number;
  log2(x: number): number;
  max(...values: Array<number>): number;
  min(...values: Array<number>): number;
  pow(x: number, y: number): number;
  random(): number;
  round(x: number): number;
  sign(x: number): number;
  sin(x: number): number;
  sinh(x: number): number;
  sqrt(x: number): number;
  tan(x: number): number;
  tanh(x: number): number;
  trunc(x: number): number;
};


declare class Boolean {
  static (value:any):boolean;
  valueOf(): boolean;
}

declare class Number {
  /*static EPSILON: number;
  static MAX_SAFE_INTEGER: number;
  static MAX_VALUE: number;
  static MIN_SAFE_INTEGER: number;
  static MIN_VALUE: number;
  static NaN: number;
  static NEGATIVE_INFINITY: number;
  static POSITIVE_INFINITY: number;*/
  /*static (value:any):number;*/
  /*static isFinite(value: any): boolean;
  static isInteger(value: any): boolean;
  static isNaN(value: any): boolean;
  static isSafeInteger(value: any): boolean;*/
  static parseFloat(value: string): number;
  static parseInt(value: string): number;
  toExponential(fractionDigits?: number): string;
  toFixed(fractionDigits?: number): string;
  toPrecision(precision?: number): string;
  toString(radix?: number): string;
  valueOf(): number;
}
