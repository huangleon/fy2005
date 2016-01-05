#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", HIG"���ƶ�����"NOR);
    set("long", @LONG
���ƶ��Ÿ����ɣ���Լ�������࣬�����ĳ�����������ȭͷ���С��������
�Ŷ���Լ���ɣ���Լÿ������ʱ���ͻ��ٱ����ء���������������׽��֮��Ĺ�
��ͨ�����Ŷ���������һ���ϳ�ǽ��խ�ݡ�����ٷ��轻��������䣱�����ƽ�
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"east" : "/d/fycycle/fyeast",
	"west" : __DIR__"ecloud5",
	"up" : AREA_FYWALL"eupgate",
      ]));
    set("objects", ([
	__DIR__"npc/wind_soldier" : 2,
	__DIR__"npc/cloud_soldier": 2, 
      ]) );
    set("outdoors", "fengyun");
    set("coor/x",300);
    set("coor/y",0);
    set("coor/z",0);
    setup();
}



int valid_leave(object me, string dir)
{
    object *inv;
    object ob;
    int i;
    if( userp(me) && ob=present("garrison", this_object()))
    {
	if( dir == "west" )	{
	    inv = all_inventory(me);
	    for(i=0; i<sizeof(inv); i++)	{
		if((int)(inv[i]->query("weapon_prop")) && (int)(inv[i]->query("equipped")))
		    return notify_fail(ob->name()+"����ȵ��������ֱֳ�������Ƴǣ�\n");	
	    }
	}

	if ( dir == "west" && me->is_naked())  {
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
	    return 
	    notify_fail(ob->name()+"����ȵ��������˵Ȳ����ϵǻ���ǽ��\n");
	}
	
    }

    if( userp(me))
    {
	if (dir == "west" && me->query_temp("annie/xiangsi_enterance") == 2)
	    me->set_temp("annie/xiangsi_enterance",3);
	else if (dir == "east" && me->query_temp("annie/xiangsi_enterance") == 4)
	    me->set_temp("annie/xiangsi_enterance",5);
	else
	    me->delete_temp("annie/xiangsi_enterance");
    }

    return 1;

}
