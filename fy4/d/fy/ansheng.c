#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", "�����ײĵ�");
    set("long", @LONG
���ſڵ������Ǽ����ѱ�������ɹ�ñ�����ɫ�Ļ�Ȧ����ڵĵ��Ϸ��ż��ڴ�
��ã�����û������ı�Ƥ�ײġ� �����ǽ�����ҵĹ��ż���ֽǮ��ֽ����ǽ��
����һ���Ϻõĺ�ľ�ײģ����׸��ƺ���û�иǺá�
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"west" : __DIR__"stone2",
      ]));
    set("objects", ([
	__DIR__"npc/cafen" : 1,
	__DIR__"npc/an_huoji" : 1,
      ]) );

    set("coor/x",260);
    set("coor/y",80);
    set("coor/z",0);
    set("map","fyeast");
    setup();
}

void init() {
    add_action("do_push","push");
}

int do_push(string arg) {
    object hu, me;
    me = this_player();
    if(!arg) return 0;
    if(arg != "coffin" && arg != "�ײ�") {
	return 0;
    }
    	if(REWARD_D->riddle_check( me, "��̽����")!=3
    		&& !REWARD_D->check_m_success( me, "��̽����")){
			return notify_fail("�ײģ������������ǲ�Ҫ����Ϊ�\n");
    }
    if(present("huo ji", this_object())) {
		hu = present("huo ji", this_object());
		message_vision("$N�Ʋ����������$n��ǰ��Ц�Ǻǵĵ�����λ�͹٣���㿴����㿴����\n",
	  		hu, this_player());
		return 1;
    }
    message_vision(HIY"\n\n$N�����ƿ��ײĸ��ӣ�һ����С�ģ�������������ȥ��\n\n"NOR,this_player());
    this_player()->move(AREA_CAVE"storage");
    return 1;
}
