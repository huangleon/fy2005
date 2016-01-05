inherit ROOM;
#include <ansi.h>

void create()
{
    set("short", HIG"����������"NOR);
    set("long", @LONG
�����Ÿ�С���ƾɣ��س�����б���ź�ӣñ��§�ų�ǹ�ڴ��˯��Ҳ����Ϊ
��������ס��ƶ���õ�֮ͽ��������ΰ������������Ǻܺá�����ӹ�֮ʱ������
���������裬ҹĻ����֮�󣬲Һź���Ц������˷���
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"west" : "/d/fycycle/fywest",
	"east" : __DIR__"wcloud5",
	"up"   : AREA_FYWALL"wupgate",
      ]));
    set("objects", ([
	__DIR__"npc/wind_soldier": 2, 
	__DIR__"npc/cloud_soldier": 2, 
      ]) );
    set("outdoors", "fengyun");
    set("coor/x",-300);
    set("coor/y",0);
    set("coor/z",0);
    set("map","fywest");
    setup();
}


int valid_leave(object me, string dir)
{
    object *inv;
    object ob;
    int i;
    if( userp(me) && ob=present("garrison", this_object()))
    {
		if( dir == "east")	{
		    inv = all_inventory(me);
		    for(i=0; i<sizeof(inv); i++)	{
			if((int)(inv[i]->query("weapon_prop")) && (int)(inv[i]->query("equipped")))
			    return notify_fail(ob->name()+"����ȵ��������ֱֳ�������Ƴǣ�\n");	
		    }
		}

		if ( dir == "east" && me->is_naked()) {
			if (me->query("age")<=11)
				 tell_object(me,ob->name()+"����üͷ˵��С���ӹ���ƨ��������ȥ����ʲô���ӣ�\n\n");
			else
				return notify_fail(ob->name()+"����ȵ�������������ҡ���У��ɺ���ͳ����\n");
		}
	
		if( dir == "up")       {
	    	inv = all_inventory(me);
	    	for(i=0; i<sizeof(inv); i++)
		    {
				if(((string)(inv[i]->name()) == "����ս��") && (int)(inv[i]->query("equipped")))
			    return 1;
		    }
	    	return	notify_fail(ob->name()+"����ȵ��������˵Ȳ����ϵǻ���ǽ��\n");
		}
    }

	return 1;
}
