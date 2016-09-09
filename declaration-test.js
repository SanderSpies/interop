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
  // assert(condition: mixed, ...data: Array<any>): void;
  clear(): void;
  count(label: string): void;
  debug(...data: Array<any>): void;
  dir(...data: Array<any>): void;
  dirxml(...data: Array<any>): void;
  error(...data: Array<any>): void;
  /*_exception(...data: Array<any>): void;
  group(...data: Array<any>): void;
  groupCollapsed(...data: Array<any>): void;
  groupEnd(): void;
  info(...data: Array<any>): void;
  log(...data: Array<any>): void;
  profile(name: string): void;
  profileEnd(): void;
  table(tabularData: { [key: string]: any } | Array<{ [key: string]: any }> | Array<Array<any>>): void;
  time(label: string): void;
  timeEnd(label: string): void;
  timeStamp(label?: string): void;
  trace(...data: Array<any>): void;
  warn(...data: Array<any>): void;*/
};
