#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "��ɽ��԰");
        set("long", @LONG
��ɽ����һ����԰��һƬ�޼�����Ĳ������г��У����˶�ߵĲ����ϳ�����
��������ҶƬ���������괦������֮�У����Դ�ҽд������԰�ɵĲ衰����衱��
һ��СϪ�Ӳ�԰��������ȥ��·����һ�����ɲ�Ů��Ϣ��Сͤ�ӡ�
LONG
        );
  	set("exits", ([ 
 		"eastdown" : __DIR__"renzi",
	]));
	
	set("resource/water", 1);
    set("liquid/container","����Ϫ");
    set("liquid/name","����Ϫˮ");
    set("outdoors", "huangshan");
    set("no_lu_letter",1);
	set("coor/x",-35);
	set("coor/y",-5);
	set("coor/z",20);
	setup();
}

void init(){
	object me;
	me = this_player();
	call_out("girl_come", random(30), me);
}

int girl_come(object me) {
	int i;
	object obj, girl;
	i = NATURE_D->get_season();
	if(!me || environment(me) != this_object()) {
		return 0;
	}
	girl = present("caicha girl", this_object());
	if( i!= 4 && NATURE_D->is_day_time() && !objectp(girl)) {
		message_vision(HIG"һ������ĸ������������ɲ�Ů�Ӳ�����ת�˳�����\n"NOR, me);
		girl = new(__DIR__"npc/tgirl");
		if(objectp(girl)){
			girl->move(this_object());
		}
	}	
	return 1;
}



