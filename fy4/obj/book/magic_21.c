// magic_book.c

inherit ITEM;

void create()
{
        set_name("ħ�����", ({ "magicbook" }));
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",                        
"����һ��ħ�����ţ�����˵��һЩϡ��Źֵĺ�һ�����ѧ��ͬ�Ķ�����
ѧϰ���������߷�����magic��\n"
                );
                set("value", 200);
                set("material", "paper");
                set("skill", ([
                        "name":     "magic",
                    	"exp_required": 100,
                        "sen_cost":  	5, 
                      	"difficulty":  	10,
                       	"max_skill":  	20 
                ]) );
        }
	::init_item();
}
 
