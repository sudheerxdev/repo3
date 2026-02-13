class Solution {
    public int numberOfSubstrings(String s) {
        int n = s.length();
        int[] pref = new int[n + 1];
        for (int i = 0; i < n; i++)
            pref[i + 1] = pref[i] + (s.charAt(i) == '1' ? 1 : 0);

        List<Integer> Z = new ArrayList<>();
        for (int i = 0; i < n; i++)
            if (s.charAt(i) == '0') Z.add(i);
        int m = Z.size();

        long ans = 0;  

        int i = 0;
        while (i < n) {
            if (s.charAt(i) == '0') { i++; continue; }
            int j = i;
            while (j < n && s.charAt(j) == '1') j++;
            long len = j - i;
            ans += len * (len + 1) / 2;
            i = j;
        }

        int B = (int)Math.sqrt(n) + 2;

        for (int a = 0; a < m; a++) {
            int Lmin = (a == 0 ? 0 : Z.get(a - 1) + 1), Lmax = Z.get(a);
            if (Lmin > Lmax) continue;

            for (int z = 1; z <= B; z++) {
                int b = a + z - 1;
                if (b >= m) break;

                int Rmin = Z.get(b), Rmax = (b + 1 < m ? Z.get(b + 1) - 1 : n - 1);
                if (Rmin > Rmax) continue;

                int need = z * z, r = Rmin;

                for (int l = Lmin; l <= Lmax; l++) {
                    if (pref[Rmax + 1] - pref[l] < need) continue;
                    while (r <= Rmax && pref[r + 1] - pref[l] < need) r++;
                    if (r > Rmax) break;
                    ans += (Rmax - r + 1);
                }
            }
        }

        return (int) ans;  
    }
}
