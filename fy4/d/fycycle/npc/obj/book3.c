// An example book

inherit ITEM;

void create()
{
	set_name("�糾��" , ({ "fengchen book", "book" }) );
        set_weight(600);
        set("unit", "��");
        set("long", "����һ�����������˷糾����֮��׿��������������Ż����Ѫд�͡� 
������������ޱȡ� \n");
        set("value", 100000);
        set("no_drop", 1);
        set("no_get", 1);
        set("no_sell", 1);
        set("skill", ([
                "name":                 "foreknowledge",      
                "exp_required": 200000,       
                "sen_cost":             10,
                "difficulty":   20,  
                "max_skill":    100,     
        ]) );
}
 
