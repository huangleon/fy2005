inherit ROOM;
#include <ansi.h>
void create()
{
    set("short", HIW"�۲���"NOR);
    set("long", @LONG
ˮ���۲��ᣬɽ��ü��ۡ���������ȥ�Ǳߣ�ü��ӯӯ������̶�һ��������
�۵Ĳ�����ȴ�����������ķ��Ƴǵ��������������۲��ᡱ˵�ı��Ǵ˴���Ҹ�
���ûʵ�Ϸ¥�����Ƴ��е���ʿ�����и�ӹ���ŵ�ϲ�ã��Դӽ�Ǯ������Ϲٽ��
�ڴ˳����ʽ������Ϸ¥��ȫ�����ص����е�������Ϸ�����ǣ��޲����ڴ˵�̨
Ϊ�٣�����֮ʢ���������Ե������Ҳʱ��΢��������Ϸ��
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"north" : __DIR__"wcloud1",
	"southup" : __DIR__"theater2",
      ]));
    set("objects", ([
	__DIR__"npc/kid": 2,
      ]) );


    set("outdoors", "fengyun");
    set("coor/x",-80);
    set("coor/y",-20);
    set("coor/z",0);
    set("map","fywest");
    setup();
}

int	valid_leave(object who, string dir)
{
    if (dir == "southup")
	return notify_fail("Ϸ̨֮�ϲ���Ѱ���˵����㡣\n");
    return ::valid_leave(who,dir);
}


void init()
{
    remove_call_out("greeting");
    call_out("greeting",1);
}

void greeting()
{
    object room,me;
    object *olist;
    mixed *local;
    int i,flag=0;
    local = NATURE_D->getTime(time());
    if (local[1] == 4)
    {
	if (query("create_void") < local[2])
	{
	    room = find_object(__DIR__"theater2");
	    if (!room)
		room = load_object(__DIR__"theater2");
	    present("silencer",room)->do_ggyy();
	    set("create_void",local[2]);
	}
    }
    if (local[1] == 8)
    {
	if (query("create_void2") < local[2])
	{
	    room = find_object(__DIR__"theater2");
	    if (!room)
		room = load_object(__DIR__"theater2");
	    present("sinny",room)->do_ggyy();
	    set("create_void2",local[2]);
	}
    }
    remove_call_out("greeting");
    call_out("greeting",60);
}
/*

���������������X�Y
���������������U�t�r
���������������U���t�r
���������������U�����t�r
���������������U��������
���������������^�k�k�k�_

��������������- FengYun - ������
������������annie 08.2003
������dancing_faery@hotmail.com
*/
