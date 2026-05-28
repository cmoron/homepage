# Refonte CSS — charte « cosy british désuet »

**Date** : 2026-05-28
**Périmètre** : `index.html`, `articles/index.html`, `articles/architecture/*.html`
**Hors périmètre** : `resume.html`, `resume_fr.html` (les CV gardent leur charte actuelle), `carnet-ecoute-piano.html` (palette claire burgundy + Cormorant, ambiance volontairement distincte).
**Type** : pur restyling, structure HTML et arborescence inchangées.

## Intention

Faire glisser la palette de moron.at d'une chaleur orange-tech vers une ambiance **club anglais désuet** : vert anglais profond comme couleur d'identité, cuir cognac comme signal d'action, et un grain de gravure asymétrique sur tous les fonds. La typographie système reste, le markup ne bouge pas.

## Charte arrêtée

### Palette (tokens CSS)

| Token | Valeur | Rôle |
|---|---|---|
| `--bg` | `#14120e` | Fond global (full-bleed sur toutes les pages) |
| `--paper` | `#181610` | Surface de lecture (carte article, panneaux) |
| `--fg` | `#ece5d6` | Texte principal |
| `--muted` | `#948b7d` | Texte secondaire, méta |
| `--faint` | `#4b4439` | Texte tertiaire, séparateurs lointains |
| `--rule` | `#2c2820` | Bordures, séparateurs |
| `--tag-bg` | `#221e17` | Fond des pills neutres (méta non-catégorisée) |
| `--green` | `#1d3a2f` | **Nouveau.** Vert anglais — structure, citations, catégories |
| `--green-fg` | `#5a957e` | **Nouveau.** Texte/icône sur fond `--green` |
| `--accent` | `#a35a32` | **Modifié** (avant : `#e07b4a`). Cognac — actions, points chauds |
| `--accent-fg` | `#c97a52` | **Nouveau.** Cognac sur texte foncé (liens, italique titre) |

### Rôles couleurs

- **Vert (`--green`)** : pills de catégorie (`Architecture`, `Notes`…), bordure et fond pâle des blockquotes, surfaces de panneaux/asides, séparateurs de section accentués.
- **Cognac (`--accent` / `--accent-fg`)** : liens et leur hover, italique dans les titres `h2`/`h3` (pattern existant `em` à l'intérieur du `h2`), flèche du lien `back`, label des catégories en méta d'entrée, sélection texte (`::selection`), barre verticale "actions" rare.
- **Texte/fond neutres** : inchangés.

### Texture — gravure hachurée asymétrique

```css
body::before {
  content: "";
  position: fixed; inset: 0;
  pointer-events: none;
  z-index: 0;
  background-image:
    repeating-linear-gradient(135deg, rgba(236, 229, 214, 0.04) 0 1px, transparent 1px 6px),
    repeating-linear-gradient( 45deg, rgba(236, 229, 214, 0.025) 0 1px, transparent 1px 9px);
}
```

- **Homepage et articles index** : la gravure couvre toute la page (la grille `main` flotte directement sur le fond hachuré).
- **Articles** (`articles/architecture/*.html`) : la gravure couvre `body`, et `main` (ou un wrapper équivalent existant) devient une **carte papier** : `background: var(--paper)`, padding interne plus généreux, `border: 1px solid var(--rule)`, `border-radius: 6px`, marges latérales préservées sur mobile.

### Typographie

Stack système actuel **conservé tel quel** :

- Corps & titres : `ui-serif, Charter, "Iowan Old Style", "Apple Garamond", Cambria, "Times New Roman", Georgia, serif`
- Meta, code, labels : `ui-monospace, "SF Mono", "JetBrains Mono", Menlo, Consolas, monospace`

Aucun webfont (`<link>` Google Fonts, `@font-face`) ne sera ajouté.

## Application page par page

### `index.html` (homepage)

- Header `--bg` + gravure sur `body` (fixed).
- Bloc `.identity` (terminal-style) : `.prompt` passe de orange à cognac, le reste inchangé.
- Titres `h2` des sections : couleur `--muted` inchangée, mais la barre `border-top` passe en `--rule` un peu plus contrasté côté vert si visible (sinon inchangé).
- `.entry-meta .cat` (catégorie d'article dans la liste) : couleur `--accent` (cognac, role "action").
- `.entry-title em` (italique dans le titre) : `--accent-fg` (cognac clair).
- Liens : `--accent-fg`, soulignement préservé.

### `articles/index.html`

- Même base que la homepage (full-bleed gravure).
- Pills de catégorie (s'il y en a) : `background: var(--green); color: var(--green-fg);`
- Liens et hovers : `--accent-fg`.

### `articles/architecture/*.html` (4 articles à la date)

- `body` : fond `--bg` + gravure fixed.
- Élément racine de lecture (`main` ou wrapper existant) : devient la **carte papier** :
  - `background: var(--paper)`
  - `border: 1px solid var(--rule)`
  - `border-radius: 6px`
  - padding interne accru (`clamp(1.8rem, 5vw, 3rem)` horizontal, `2.5rem 0` vertical)
  - même `max-width` qu'actuel (≈ 42rem) — pas de changement de gabarit
- Lien `.back` : `--accent-fg` pour la flèche, `--muted` pour le texte (inchangé sauf accent).
- `.meta` (date / catégorie) : couleur catégorie `--accent-fg`, séparateurs `--faint`.
- Titres :
  - `h1 em`, `h2 em`, `h3 em` : `--accent-fg` (italique = highlight d'action / mise en relief).
  - `h2` : `border-top` inchangée (séparateur de section déjà en `--rule`).
- `blockquote` :
  - `border-left: 3px solid var(--green-fg);`
  - `background: rgba(29, 58, 47, 0.18);` (vert structure, très transparent)
  - `padding: 0.6rem 1rem;`
  - couleur texte inchangée (`--fg`).
- `code`, `pre` : héritent du look existant (mono stack), mais le fond passe de `--tag-bg` à un mélange plus papier : `background: rgba(20, 18, 14, 0.6);` sur fond `--paper`, et `--accent-fg` pour les `code` inline (déjà cognac → on bascule simplement sur le nouveau ton). Bordure subtile `--rule`.
- `.section-label` : passe de `--accent` à `--green-fg` (label = catégorie/section = structure).
- Liens internes : `--accent-fg`, soulignement préservé.

### Détails transverses

- `::selection` : `background: var(--accent); color: var(--bg);`
- Focus visible : `outline: 2px solid var(--accent-fg); outline-offset: 2px;` (manquant aujourd'hui, ajouté pour accessibilité).
- `prefers-reduced-motion: reduce` : aucun effet animé n'est introduit, donc pas de précaution supplémentaire.

## Anti-objectifs (ce qu'on ne fait pas)

- Pas de webfont (validé après essai Caslon/Garamond/Cormorant).
- Pas de dégradé radial / linear visible (banding observé). La profondeur passe par la texture, pas par le dégradé.
- Pas d'ornement figuratif fin (fleur-de-lys, quatrefoil) — la gravure hachurée gagne sur la finesse + densité requises.
- Pas de bundler, npm, framework (rappel CLAUDE.md).
- Pas de modification de la structure HTML existante, sauf ajout du wrapper `body::before` pour la gravure et, sur les articles, mise en carte du wrapper de lecture (s'il faut ajouter une classe au `main`, on le fait, mais l'arborescence DOM reste).

## Vérification

Pas de test suite. Pour valider :

1. Servir le site en local (`python3 -m http.server`) et ouvrir Playwright MCP sur :
   - `/index.html`
   - `/articles/index.html`
   - `/articles/architecture/harness.html`
   - `/articles/architecture/api-types.html`
   - `/articles/architecture/mcp-cli-api.html`
   - `/articles/architecture/hermes-vs-openclaw.html`
2. Vérifier visuellement, puis screenshot avant/après chaque page.
3. Vérifier que la console est propre (les pages chargent toutes leurs ressources).
4. Mobile : redimensionner à 360px de large, vérifier que la carte papier (articles) ne déborde pas et que la gravure ne pixelise pas.

## Fichiers attendus à modifier

- `index.html` — bloc `<style>` inline (palette tokens, lien cognac, italique, ::before sur body, accents catégorie).
- `articles/index.html` — bloc `<style>` inline si présent, ou via CSS commun.
- `articles/architecture/harness.html`, `api-types.html`, `mcp-cli-api.html`, `hermes-vs-openclaw.html` — chaque article inclut probablement quelques styles inline propres ; vérifier au cas par cas. La majorité des changements va dans `css/article.css`.
- `css/article.css` — gros du travail : tokens, texture, carte papier, blockquote, code, sections, liens.
- `css/diagrams.css` — **aucune édition.** Le fichier utilise `var(--accent)` partout pour les SVG ; il hérite automatiquement du nouveau cognac via le changement du token. À vérifier visuellement après refonte pour confirmer que le rendu des diagrammes reste lisible.

Aucun fichier nouveau requis. Aucune dépendance ajoutée.
