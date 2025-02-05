module.exports = {
  purge: [],
  darkMode: true, // or 'media' or 'class'
  theme: {
    extend: {},
  },
  variants: {
    extend: {},
  },
  content: [
    "./templates/**/*.html", // Untuk membaca semua file HTML dalam folder templates
    "./static/**/*.css",     // Jika ada file CSS tambahan di static
  ],
  
  plugins: [],
};

