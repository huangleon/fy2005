// spells_book.c

inherit ITEM;

void create()
{
        set_name("��������", ({ "spellsbook" }));
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",                        
"����һ�������飬���滭��һЩϡ��Źֵķ���,
ѧϰ��������������(spells)��\n"
                );
                set("value",200);
                set("material", "paper");
                set("skill", ([
                        "name":     	"spells",   
                        "exp_required": 100, 
                        "sen_cost":  	5, 
                        "difficulty":  	10,
                    	"max_skill":  	20

                ]) );
        }
        ::init_item();
}
 
