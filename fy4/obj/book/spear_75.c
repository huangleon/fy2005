// An example book

inherit ITEM;

void create()
{
	set_name("����ǹ��" , ({ "spear book","book"}) );
        set_weight(600);
        set("unit", "��");
        set("long", "����һ������ǹ����ү���������Ļ���ǹ����\n");
        set("value", 500);
	set("no_drop", 1);
        set("skill", ([
                "name":         "spear",      
                "exp_required": 1000000,       
                "sen_cost":      2,
                "difficulty":   15,  
                "max_skill":    74,
               	"literate":		"spear",		
				"liter_level":	65,	     
        ]) );
        ::init_item();
}
 
