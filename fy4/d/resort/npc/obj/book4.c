// An example book

inherit ITEM;

void create()
{
	set_name("�̸赶������" , ({ "shortsong-blade" }) );
        set_weight(600);
        set("unit", "��");
        set("long", "����һ�����̸ܶ赶�����书����\n");
        set("value", 0);
        set("skill", ([
                "name":                 "shortsong-blade",      
                "exp_required": 200000,       
                "sen_cost":             40,
                "difficulty":   30,  
                "max_skill":    60     
        ]) );
}
 
