#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", HIG"���Ʊ�����"NOR);
    set("long", @LONG
���Ʊ��Ÿ����ɣ���Լ�������࣬�����ĳ�����������ȭͷ���С��������
�Ŷ���Լ���ɣ���Լÿ������ʱ���ͻ��ٱ����ء���������������׽��֮��Ĺ�
��ͨ�����Ŷ���������һ���ϳ�ǽ��խ�ݡ�����ٷ��轻��������䣱�����ƽ�
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"north" : "/d/fycycle/fynorth",
	"south" : __DIR__"nwind5",
	"up"   : AREA_FYWALL"nupgate",
      ]));
    set("objects", ([
	__DIR__"npc/wind_soldier" : 2,
	__DIR__"npc/cloud_soldier": 2, 
      ]) );
    set("outdoors", "fengyun");
    set("coor/x",0);
    set("coor/y",300);
    set("coor/z",0);
    set("map","fynorth");
    setup();
}


int valid_leave(object me, string dir)
{
    object *inv;
    object ob;
    int i;
    if( userp(me) && ob=present("garrison", this_object()))
    {
	if( dir == "south" && !random(10) )	{
	    inv = all_inventory(me);
	    for(i=0; i<sizeof(inv); i++)	{
		if((int)(inv[i]->query("weapon_prop")) && (int)(inv[i]->query("equipped")))
		    return notify_fail(ob->name()+"����ȵ��������ֱֳ�������Ƴǣ�\n");	
	    }
	}

	if ( dir == "south" && me->is_naked())  {
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
	    return notify_fail(ob->name()+"����ȵ��������˵Ȳ����ϵǻ���ǽ��\n");
		}
    }
	return 1;

}

