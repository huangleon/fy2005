// An example book

inherit ITEM;

void create()
{
	set_name("��������������" , ({ "deisword" }) );
        set_weight(600);
        set("unit", "��");
        set("long", "����һ�����ܵ������������书����\n");
        set("value", 0);
        set("skill", ([
                "name":                 "deisword",      
                "exp_required": 200000,       
                "sen_cost":             35,
                "difficulty":   30,  
                "max_skill":    60     
        ]) );
}
 
