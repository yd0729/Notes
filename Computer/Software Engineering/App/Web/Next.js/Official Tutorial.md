# Basics

## Create a Next.js App

用 React 从头构建一个网络应用需要考虑的问题：

1. bundler：webpack
2. 用来 transform code 的 compiler：Babel
3. production optimization：code splitting
4. performance & SEO：预渲染一些页面，同时还要有客户端和服务器端的渲染。
5. 服务器端需要写一些代码使 React app 可以访问到数据存储。

➡️ 一个具有正确抽象层级的 framework 可以解决这些问题，最好还要有良好的开发者体验。

### Next.js: The React Framework

+ An intuitive page-based routing system (with support for dynamic routes)
+ Pre-rendering, both **static generation** (SSG) and **server-side rendering** (SSR) are supported.
+ **Automatic code splitting** for faster page loads. 自动分割代码，每个页面只会加载必需的代码,页面之间是分隔的——某个页面抛出了错误，剩余的页面也可以正常使用。在生产构建中，只要 Link 组件出现在浏览器的可视范围内（viewport），Next.js 就会在后台**自动预取**（prefetch）对应的页面（😯，nice），等到用户点击链接时，加载就基本上是一瞬间的事儿了。
+ **Client-side routing** with optimized prefetching
+ **Built-in CSS and Sass support**, and support for any CSS-in-JS library.
+ Development environment with Fast Refresh support：Next.js 的 development server 会自动应用对于文件的更改，不需要刷新浏览器。
+ **API routes** to build API endpoints with Serverless Functions
+ **Fully extendable**

### Create a Next.js app

```zsh
npx create-next-app nextjs-blog --use-npm --example "https://github.com/vercel/next-learn/tree/master/basics/learn-starter"
```

bootstrap 一个 Next.js app ，--example 将后面的文件作为模板。

### Run the development server

```zsh
cd nextjs-blog
npm run dev
```

## Navigate Between Pages

### Pages in Next.js

1. Next.js 的页面是从目录 pages 中的文件导出的 React 组件。页面的路由地址就是对应文件在 pages 中的位置，无需配置。
2. `pages/index.js` 对应的路由是 `/ `，不是 `/index` ，这个有点特殊。

### Link Component

```typescript
import Link from 'next/link'
```

Next.js 提供了 `Link` 组件来包裹 `<a>` 标签，实现了应用内部的客户端导航。

客户端导航（Client-side navigation）：使用 JavaScript 来实现页面变换，这比传统上使用浏览器来实现导航更加快速。

```html
<h1 className="title">
  Read{' '} // {' '}能够在多行代码之间添加空格
  <Link href="/posts/first-post">
<a>this page!</a>
  </Link>
</h1>
```

1. 	如果需要链接外部页面，还是要用 `<a>`。
2. 	如果需要添加属性，比如 className ，在 `<a>` 中添加，不要在 `<Link>` 中添加。

## Assets, Metadata, and CSS

Next.js 内置支持 CSS 和 Sass 。

### Assets

Next.js 提供对静态资产的支持。**静态资产（static assets）**文件需要放在顶层的 `public` 目录下。

静态资产：包括图片、robots.txt、Google Site Verfication 等文件。`public` 目录也和 `pages` 目录一样对应路由的根路径 `/`。

### Unoptimized Image

```html
<img src="/images/profile.jpg" alt="Your Name"/>
```

需要解决的问题：

1. 确保在不同大小的屏幕上都 responsive 。
2. 用第三方工具优化图片。
3. 在图片进入 viewport 后才加载图片。

### Image Component and Image Optimization

Next.js 默认提供图片优化。当浏览器支持时，Next.js 会以  WebP 等现代的图片格式提供图片。这会避免让大图片显示在一个小得多的 viewport 中。在未来，Next.js 也会以更新的图片格式提供图片，只要浏览器支持。自动图片优化支持任何来源的图片，即使图片来自外部的数据源，比如 CMS 。

### Using the Image Component

Next.js 根据需要（用户请求）优化图片，而不是在构建时优化，所以构建时间不会像在使用静态网站生成器和纯静态解决方案时那样随着图片数量的增加而增加。图片默认是懒加载的（当图片滚动进视界时才加载），页面的加载速度不会收到视界之外的图片的影响。
