import java.util.ArrayList;
import java.util.Scanner;

public class CRUDApp {
    private static ArrayList<Item> items = new ArrayList<>();
    private static int idCounter = 1;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        boolean running = true;

        while (running) {
            System.out.println("\n--- Menu CRUD ---");
            System.out.println("1. Create Item");
            System.out.println("2. Read Items");
            System.out.println("3. Update Item");
            System.out.println("4. Delete Item");
            System.out.println("5. Exit");
            System.out.print("Choose an option: ");
            int choice = scanner.nextInt();
            scanner.nextLine();  // consume newline character

            switch (choice) {
                case 1:
                    createItem(scanner);
                    break;
                case 2:
                    readItems();
                    break;
                case 3:
                    updateItem(scanner);
                    break;
                case 4:
                    deleteItem(scanner);
                    break;
                case 5:
                    running = false;
                    break;
                default:
                    System.out.println("Invalid option, try again.");
            }
        }

        scanner.close();
    }

    private static void createItem(Scanner scanner) {
        System.out.print("Enter item name: ");
        String name = scanner.nextLine();
        Item newItem = new Item(idCounter++, name);
        items.add(newItem);
        System.out.println("Item created: " + newItem);
    }

    private static void readItems() {
        if (items.isEmpty()) {
            System.out.println("No items available.");
        } else {
            for (Item item : items) {
                System.out.println(item);
            }
        }
    }

    private static void updateItem(Scanner scanner) {
        System.out.print("Enter item ID to update: ");
        int id = scanner.nextInt();
        scanner.nextLine();  // consume newline character
        Item itemToUpdate = findItemById(id);

        if (itemToUpdate != null) {
            System.out.print("Enter new name: ");
            String newName = scanner.nextLine();
            itemToUpdate.setName(newName);
            System.out.println("Item updated: " + itemToUpdate);
        } else {
            System.out.println("Item not found.");
        }
    }

    private static void deleteItem(Scanner scanner) {
        System.out.print("Enter item ID to delete: ");
        int id = scanner.nextInt();
        Item itemToDelete = findItemById(id);

        if (itemToDelete != null) {
            items.remove(itemToDelete);
            System.out.println("Item deleted: " + itemToDelete);
        } else {
            System.out.println("Item not found.");
        }
    }

    private static Item findItemById(int id) {
        for (Item item : items) {
            if (item.getId() == id) {
                return item;
            }
        }
        return null;
    }
}
