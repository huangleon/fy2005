
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name("����", ({"gongwen"}) );
	set_weight(5);
	set("long", "�����ż��÷��˵Ĺ���ֽ��̧ͷ���Ż�δ��д����print��\n");
	set("unit", "��");
        set("value", 10000);
        set("official_seal",1);
	::init_item();
}

void init()
{
  	if(this_player()==environment())
  		add_action("do_print","print");

}

int do_print(string arg)
{
        object obj, tarobj, tempobj;
        string sheet, target;

	if( !arg || sscanf(arg, "%s", target)!=1 )
		return notify_fail("ָ���ʽ��print <����> \n");
		
	if (query("printed"))
		message_vision("$N�ͳ�����Ƥ�ѹ���ֽ��̧ͷ���˲���\n", this_player());
		
	tempobj = present(target, environment(this_player()));
	if (tempobj)
	{
		if (!living(tempobj))
		{
			tarobj = find_living(target);
		}
		else
			tarobj = tempobj;
	}
	else tarobj = find_living(target);	
	
	if( !tarobj || (tarobj && tarobj->query("wiz_invis"))) {
		message_vision("$N��" + target + "����$n��������һ���ϡ�\n", this_player(), this_object());
		this_object()->set("long",
			"����һ�Ź���ֽ�����漩�ô���һ����д�š�" + target + "����\n");
        }
        else {
	   	message_vision("$N��" + tarobj->name() + "����$n��������һ���ϡ�\n", this_player(), this_object());
	   	this_object()->set("hunted_name",tarobj->query("id"));
	   	this_object()->set("long",
				"����һ�Ź���ֽ�����漩�ô���һ����д�š�" + tarobj->name() + "����\n");
           	if (userp(tarobj)) this_object()->set("players",1);
        }
        this_object()->set("targetid", target);
        this_object()->set("printed",1);
        return 1;
}


