// An example book

inherit ITEM;

void create()
{
	set_name("�������" , ({ "qidaoforce" }) );
        set_weight(600);
        set("unit", "��");
        set("long", "����һ������������书����\n");
        set("value", 0);
        set("skill", ([
                "name":                 "qidaoforce",      
                "exp_required": 200000,       
                "sen_cost":             50,
                "difficulty":   40,  
                "max_skill":    60     
        ]) );
}
 
