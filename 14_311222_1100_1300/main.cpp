#include<iostream>
#include<string>
#include<vector>

enum Color {BLUE, GREEN, YELLOW, RED};
enum Size {SMALL, LARGE, MEDIUM, HUGE};
enum Price {LOW, MID, HIGH};   // low = 50-150, mid = 151, 250, high = 251-350


class Product{
    private:
        std::string name;
        Size size;
        Color color;
        double price;
    
    public:
        Product(std::string name, Size size, Color color, double price){
            this->name = name;
            this->size = size;
            this->color = color;
            this->price = price;
        }

        std::string getName(){
            return name;
        }

        Size getSize(){
            return size;
        }

        Color getColor(){
            return color;
        }

        double getPrice(){
            return price;
        }
};


// method 1
// class ProductFilter{
//     public:
//         static void filterByColor(std::vector<Product> &products, Color color){
//             for(auto &p : products){
//                 if(p.getColor() == color){
//                     std::cout<<p.getName()<<"\n";
//                 }       
//             }
//         }

//         static void filterBySize(std::vector<Product> &products, Size size){
//             for(auto &p : products){
//                 if(p.getSize() == size){
//                     std::cout<<p.getName()<<"\n";
//                 }       
//             }
//         }

//         static void filterByColorAndSize(std::vector<Product> &products, Color color, Size size){
//             for(auto &p : products){
//                 if(p.getColor()==color && p.getSize()==size){
//                     std::cout<<p.getName()<<"\n";
//                 }       
//             }
//         }
// };




// abstract class or interface, we cant create object of this class
class ISpecification{
    public:
        virtual bool isSatisfiedBy(Product &product) = 0;
};


// concrete class, implements the interface
class ColorSpecification : public ISpecification{
    private:
        Color color;

    public:
        ColorSpecification(Color color){
            this->color = color;
        }

        bool isSatisfiedBy(Product &product){
            return product.getColor() == color;
        }
};


// concrete class, implements the interface
class SizeSpecification : public ISpecification{
    private:
        Size size;

    public:
        SizeSpecification(Size size){
            this->size = size;
        }

        bool isSatisfiedBy(Product &product){
            return product.getSize() == size;
        }
};


// concrete class, implements the interface
class PriceSpecification : public ISpecification{
    private:
        Price price;

    public:
        PriceSpecification(Price price){
            this->price = price;
        }

        bool isSatisfiedBy(Product &product){
            if(price == LOW){
                return product.getPrice()>=50000 && product.getPrice()<=150000;
            }else if(price == MID){
                return product.getPrice()>=150001 && product.getPrice()<=250000;
            }else{
                return product.getPrice()>=250001 && product.getPrice()<=350000;
            }
        }
};


class ProductFilter{
    public:
        // only color, only size
        static void filter(std::vector<Product> &products, ISpecification* specification){
            for(auto &p : products){
                if(specification->isSatisfiedBy(p)){
                    std::cout<<p.getName()<<"\n";
                }
            }
            std::cout<<"\n\n";
        }
        
        // handles comb
        static void filter(std::vector<Product> &products, std::vector<ISpecification*> specifications){
            for(auto &p : products){
                bool flag = 1;
                for(auto spec : specifications){
                    if(!spec->isSatisfiedBy(p)){
                        flag = 0;
                        break;
                    }
                }
                if(flag){
                    std::cout<<p.getName()<<"\n";
                }
            }
            std::cout<<"\n\n";
        }
};




int main(){
    std::vector<Product> products;
    products.emplace_back(Product("CAR", MEDIUM, GREEN, 100000));
    products.emplace_back(Product("TRUCK", LARGE, BLUE, 200000));
    products.emplace_back(Product("BUS", HUGE, BLUE, 300000));
    

    // method 1
    //ProductFilter::filterByColorAndSize(products, LARGE);
    //ProductFilter::filterByColorAndSize(products, BLUE, LARGE);

    
    // method 2
    ISpecification* specification = new SizeSpecification(LARGE);   
    ProductFilter::filter(products, specification);
    delete specification;

    std::vector<ISpecification*> specifications;
    specifications.emplace_back(new ColorSpecification(GREEN));
    specifications.emplace_back(new SizeSpecification(MEDIUM));
    specifications.emplace_back(new PriceSpecification(LOW));
    ProductFilter::filter(products, specifications);
    for(auto spec : specifications){
        delete spec;
    }
    
    return 0;
}