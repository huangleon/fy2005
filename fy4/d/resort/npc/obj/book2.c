// An example book

inherit ITEM;

void create()
{
	set_name("һ��÷��������" , ({ "meihua-shou" }) );
        set_weight(600);
        set("unit", "��");
        set("long", "����һ������һ��÷���ֵ��书����\n");
        set("value", 0);
        set("skill", ([
                "name":                 "meihua-shou",      
                "exp_required": 200000,       
                "sen_cost":             30,
                "difficulty":   20,  
                "max_skill":    60     
        ]) );
}
 
