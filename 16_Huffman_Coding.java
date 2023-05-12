import java.util.*;

class HuffmanNode implements Comparable<HuffmanNode> {
    int frequency;
    char symbol;
    HuffmanNode left;
    HuffmanNode right;

    public HuffmanNode(int frequency, char symbol, HuffmanNode left, HuffmanNode right) {
        this.frequency = frequency;
        this.symbol = symbol;
        this.left = left;
        this.right = right;
    }

    public int compareTo(HuffmanNode other) {
        return this.frequency - other.frequency;
    }
}

public class HuffmanCoding {
    public static void main(String[] args) {
        String str = "this is a test string";
        compress(str);
    }

    public static void compress(String str) {
        int[] frequencies = new int[256];
        for (int i = 0; i < str.length(); i++) {
            frequencies[str.charAt(i)]++;
        }

        PriorityQueue<HuffmanNode> pq = new PriorityQueue<>();
        for (int i = 0; i < 256; i++) {
            if (frequencies[i] > 0) {
                pq.add(new HuffmanNode(frequencies[i], (char)i, null, null));
            }
        }

        while (pq.size() > 1) {
            HuffmanNode left = pq.remove();
            HuffmanNode right = pq.remove();
            HuffmanNode parent = new HuffmanNode(left.frequency + right.frequency, '\0', left, right);
            pq.add(parent);
        }

        HuffmanNode root = pq.remove();
        Map<Character, String> codes = new HashMap<>();
        generate_codes(root, "", codes);
        System.out.println("Codes:");
        for (char c : codes.keySet()) {
            System.out.println(c + ": " + codes.get(c));
        }

        System.out.print("Compressed string: ");
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < str.length(); i++) {
            sb.append(codes.get(str.charAt(i)));
        }
        System.out.println(sb.toString());
    }

    public static void generate_codes(HuffmanNode node, String code, Map<Character, String> codes) {
        if (node.left == null && node.right == null) {
            codes.put(node.symbol, code);
            return;
        }
        generate_codes(node.left, code + "0", codes);
        generate_codes(node.right, code + "1", codes);
    }
}
