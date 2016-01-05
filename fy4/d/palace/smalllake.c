inherit ROOM;
void create()
#include <command.h>
{
    set("short", "С��");
    set("long", @LONG
Ϫˮ����������һ��СС�ĺ���������Ⱥɽ���ƣ�������ľ������С���ߴ
�������ּ䴫����΢�紵�����������ˡ���ˮ������ɫ�������䲻�󣬿ɺ�ˮȴ��
���ɲ⡣
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"west" : __DIR__"river",
      ]));
    set("item_desc", ([
	"lake": "����Դ�����Ǳ�������壩�����ס�\n",
	"water" : "����Դ�����Ǳ�������壩�����ס�\n",
	"��ˮ" : "����Դ�����Ǳ�������壩�����ס�\n"
      ]) );

    set("outdoors","fengyun");
    set("coor/x",-70);
    set("coor/y",60);
    set("coor/z",10);

    setup();
}

void init()
{
    add_action("do_dive", "dive");
}

int do_dive()
{
    object *inv,me;
    object bottom;
    int i;
    string	objname;

    me = this_player();

    bottom = load_object(__DIR__"bottom");
    if (bottom->query("underwater") > me->query_skill("swimming",1))
	return notify_fail("�����Ӿ����̫�û����ȥѽ��\n");
    inv = all_inventory(me);
    for(i=0; i<sizeof(inv); i++) {
		objname = (string)inv[i]->query("name");
		if( !inv[i]->query("waterproof") && objname != "«έ")
	    	DROP_CMD->do_drop(me, inv[i]);
    }
    message_vision("$N�ѹ��������·���һ�����������ˮ�У�\n",me);
    if(bottom) me->move(bottom);
    return 1;
}
