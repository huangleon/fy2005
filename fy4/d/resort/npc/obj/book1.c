// An example book

inherit ITEM;

void create()
{
	set_name("��粽������" , ({ "fall-steps" }) );
        set_weight(600);
        set("unit", "��");
        set("long", "����һ��������粽�����书����\n");
        set("value", 0);
        set("skill", ([
                "name":                 "fall-steps",      
                "exp_required": 200000,       
                "sen_cost":             30,
                "difficulty":   20,  
                "max_skill":    60     
        ]) );
}
 
