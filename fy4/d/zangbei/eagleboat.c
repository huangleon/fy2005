inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "ӥ��");
        set("long", @LONG
���Ҵ���붼�������ӽ��ɣ����������ģ��װ�Ҳ�ǣ����Դ����ر��ᡣ��
��װ������ϸ���İ壬����������ѩ����ȴ���ü����͡����⻬�ľ������ɵġ���
��ֻ�ý�������ӥ������ڼװ��ϡ���������ͯ�ӣ�����һ����һ�������ʵ��⣬
��ι���ǡ�
LONG
        );
        set("exits", ([ 
	]));
	set("no_fly",1);
	set("no_fight",1);
        set("objects", ([

	]) );
	set("coor/x",-360);
        set("coor/y",100);
        set("coor/z",10);
	set("map","zbeast");
	setup();
}

int depart(object me){
	
	if (!me || environment(me)!=this_object())
		return 0;
		
	tell_object(me,CYN"
����ͯ�Ӵ����Ͻ��������ޣ����ȡ������һ����

ӥȺ���̳������������������������Ҳ���������Ӵ����������Ҵ���

����ѩ������ƽ����ɳ���ϻ�����������ʼʱ������������ȴ�ǻ�����ɣ�ֱ

���������һ�㡣������\n\n"NOR);

	me->start_busy(4);
	call_out("arrive",4,me);
	return 1;
}

int arrive(object me) {
	if (!me || environment(me)!=this_object())
		return 0;
	tell_object(me,YEL"Ҳ��֪�����˶�ã�����һ��ͣ��������\n"NOR);
	set("exits/down",AREA_GUANYIN"entrance");
	return 1;
}

int valid_leave(object who, string dir){
	if (userp(who))
	if (query("exits"))
		delete("exits");
	return 1;
}





