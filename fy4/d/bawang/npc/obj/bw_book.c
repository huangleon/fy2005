// An example book

inherit ITEM;

void create()
{
	set_name("����ǹ��" , ({ "bawang book","book"}) );
        set_weight(600);
        set("unit", "��");
        set("long", "����һ������ǹ����ү����������ǹ�ס�\n");
        set("value", 500);
        set("skill", ([
                "name":                 "xuezhan-spear",      
                "exp_required": 1500000,       
                "sen_cost":             20,
                "difficulty":   15,  
                "max_skill":   50     
        ]) );
        ::init_item();
}
 
