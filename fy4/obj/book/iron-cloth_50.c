// movebook.c

inherit ITEM;

void create()
{
        string *name= ({"������", "�������", "����", "���", "������"});
        set_name( name[random(5)] , ({ "buddbook", "book" }) );
		set_weight(600);
		if( clonep() )
			set_default_object(__FILE__);
		else {
			set("unit", "��");
		set("long","��̾��ģ���ֵ�����ҳ��֮���Ȼ����Щ����ķ��š�\n");
		set("value", 70);
		set("no_transfer",1);
		set("material", "paper");
		set("skill", ([
			"name": 	"iron-cloth",	
			"exp_required":	0,				
			"sen_cost":	2,				
			"difficulty":	20,		
			"max_skill":	49		
		]) );
	}
}
