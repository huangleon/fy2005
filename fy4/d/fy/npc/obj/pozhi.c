
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name("�������ֽƬ", ({"pozhi"}) );
	set_weight(5);
	set("long",
		"����һ���������ֽƬ����������д����(print)\n");
	set("unit", "��");
        set("value", 50000);
        ::init_item();
}

void init()
{
  if(this_player()==environment())
  add_action("do_print","print");

}

int do_print(string arg)
{
        object obj, tarobj;
        string sheet, target;

		if( !arg || sscanf(arg, "%s", target)!=1 )
			return notify_fail("ָ���ʽ��print <����> \n");
		tarobj = present(target, environment(this_player()));
		if( !tarobj) tarobj = find_living(target);
		// No more player faking wizard	
		if( !tarobj  || (objectp(tarobj) && tarobj->query("wiz_invis")))  {
	   		message_vision("$N��" + target + "д��$n�ϡ�\n", this_player(), this_object());
	   		this_object()->set("long",
			"����һ��" + this_object()->name() + "������д�ţ�" + target + "������С�֣�\n");
        }
        else {
		   message_vision("$N��" + tarobj->name() + "д��$n�ϡ�\n", this_player(), this_object());
		   this_object()->set("targetname",tarobj->name());
		   this_object()->set("targetgender",tarobj->query("gender"));
		   this_object()->set("long",
			"����һ��" + this_object()->name() + "������д�ţ�" + tarobj->name() + "������С�֣�\n");
		   this_object()->set("targetid", target);
        }
        return 1;
}
