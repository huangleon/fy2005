inherit ROOM;
#include <ansi.h>
string show_book();

void create()

{
        set("short", "����С��");
        set("long", @LONG
������İ���ܼ򵥣�Ҳ�ܾ��£�����ǽ�Ϲ���һ����������һ�������ʺ춷
���Ů�����ںӱߣ���ɫ�԰׵ÿ��¡��ʺ�Ķ�������ˮ��Ʈ������ڵ�ͷ����
���з��裬�������۾��У�������˵��������ꡣ�������½���һ��С�֡������
�����Ϸ���һ���������顣
LONG
    );
        set("exits", ([ 
		"out": __DIR__"star_room2",
		"up" : __DIR__"star_room",
		"south": __DIR__"star_room3",
	]));
        set("item_desc", ([
    		"С��":	WHT"
    ����һ�׺��ָ�������а�����������֪�������޾�˥��ɽ���꣬��ˮΪ�ߣ�
������������ѩ����غϣ��˸�������� ��\n\n"NOR,
		"picture":	WHT"
    ����һ�׺��ָ�������а�����������֪�������޾�˥��ɽ���꣬��ˮΪ�ߣ�
������������ѩ����غϣ��˸�������� ��\n\n"NOR,      		    	
		"��":	WHT"
    ����һ�׺��ָ�������а�����������֪�������޾�˥��ɽ���꣬��ˮΪ�ߣ�
������������ѩ����غϣ��˸�������� ��\n\n"NOR,      		    	
		"book": (: show_book() :),
		"��������": (: show_book() :),
		"��": (: show_book() :),
	]) );
        set("coor/x",-1690);
        set("coor/y",640);
        set("coor/z",0);
        set("no_fly",1);
	set("map","zbwest");
	setup();

}


string show_book() {
	tell_object(this_player(),"
    ����һ��������Ĵʼ���������һֻ������������������������������·���
ʱ������չ��˫���˷��ȥ�������ʼ����Ϳ�������ֻ������������һҳ�Ĵʡ�"+HIR"

    ��  ��  л  ��  ��  ��  ̫  ��  ��"NOR+ "

    ��л�˻����ٿ�������ȥ�˻������������������أ�
    ���״ʼ����ͺ���ͬ��������������ǧ�ţ��������ࡣ��������ʵ����أ�
    ����ʵ��ˣ������ǲ��Ǻͺ���������
    ����̫���飬�ǲ��Ǿͻ��úͺ���������\n\n"NOR);
    return "";
}

int valid_leave(object obj, string dir){
	
	object room,*env,*pc;
	
	if (dir=="south") {
		if (!objectp(room=find_object(__DIR__"star_room3")))
			room=load_object(__DIR__"star_room3");
		env=all_inventory(room);
		pc=filter_array(env,(: userp($1) :) );
		if (pc && sizeof(pc)) 
			return notify_fail("С����æ�ţ���һ����ٽ�ȥ�ɡ�\n");
	}
	return 1;
}
		