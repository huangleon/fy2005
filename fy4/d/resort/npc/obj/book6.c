// An example book

inherit ITEM;

void create()
{
	set_name("�ڹ��ķ�����" , ({ "force" }) );
        set_weight(600);
        set("unit", "��");
        set("long", "����һ�������ڹ��ķ����书����\n");
        set("value", 0);
        set("skill", ([
                "name":                 "force",      
                "exp_required": 200000,       
                "sen_cost":             40,
                "difficulty":   30,  
                "max_skill":    100     
        ]) );
}
 
