
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name("���͵�ֽ", ({"youzhi"}) );
	set_weight(5);
	set("long","�������Ͱߵ�����ֽƬ�������½ǲݲݵػ���һ������ͷ��
�м����źܴ�һ��հף�����д�֣�print��\n");
	set("unit", "��");
    set("value", 1);
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
		else 
			tarobj = find_living(target);	
	
		if( !tarobj || (objectp(tarobj) && tarobj->query("wiz_invis"))) {
			message_vision("$N��" + target + "д��$n�ϡ�\n", this_player(), this_object());
				this_object()->set("long",
				"����һ��" + this_object()->name() + "������д�ţ�" + target + "������С�֣�\n");
        }
        else {
	   		message_vision("$N��" + tarobj->name() + "д��$n�ϡ�\n", this_player(), this_object());
	   		set("targetname",tarobj->name());
	   		set("targetgender",tarobj->query("gender"));
	   		set("long",
			"����һ�����͵�ֽ������д�ţ�" + tarobj->name() + "������С�֣�\n");
           	if (userp(tarobj)) 
           		set("players",1);
        }
        set("targetid", target);
        return 1;
}


