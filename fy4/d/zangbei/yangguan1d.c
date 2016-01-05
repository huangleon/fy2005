inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "��ɳĮ");
        set("long", @LONG
��Ȼ��ͬһ��̫��������̫������ɳĮ�ϣ��ͺ�Ȼ����ֺ��ֶ�������Ҫ����
��ɳĮ��ɹ��ȼ�������Ƶġ�û�з磬һ˿�綼û�У�Ҳû��˿���������������£�
ɳĮ�����е����������ѽ�����һ������״̬��������ɳĮ�������������ȵ�����
�޲��ð��������Ѷ��ѹ⡣
LONG
        );
        set("exits", ([ 
		"east" : __DIR__"yangguan1d",
		"west" :__DIR__"yangguan1d",
	]));
        set("objects", ([

	]) );
	set("outdoors", "zangbei");
        set("coor/x",-80);
        set("coor/y",300);
        set("coor/z",0);
        set("map","zbeast");
	setup();
}


void 	init(){
	add_action("do_smell","smell");
	add_action("do_dig","digdown");
	add_action("do_go", "go");
	add_action("do_search","search");
}

int do_search(){
	tell_object(this_player(), "����ɳ�������˰��죬���ʲôҲû�з��֣������˷���ͨ��\n");
	return 1;
}

int do_smell(string arg){
	if (this_player()->is_busy())
		return notify_fail("��������æ��\n");
	message_vision(YEL"$N���������ñ������ŵ��ϵ�ɳ�������������š�\n"NOR,this_player());
	if (!random(5)){
		tell_object(this_player(),WHT"��Ȼ�����ƺ��ŵ���ɳ���µ�һ˿ʪ����Ҳ������ڣ�digdown����ȥ������\n"NOR);
		this_player()->set_temp("zangbei/desert_smell",1);
	}
	this_player()->start_busy(1);
	return 1;
}


int do_dig(string arg){
	object weapon, me;
	me = this_player();
	if (!weapon=me->query_temp("weapon"))
		return notify_fail("������û���ߣ���ʲô�ڣ�\n");
	if (me->is_busy())
		return notify_fail("��������æ��\n");
		
	message_vision(YEL"$N�������е�"+weapon->name()+YEL"����������������ɳ�ӡ�\n"NOR,me);
	if (!random(2) && me->query_temp("zangbei/desert_smell")) {
		tell_object(me,HIG"˳��ʪ������������ȥ���㷢�������µ�ɳ����һ��ˮ����ȷ�е�˵��
ֻ��һ��ʪ��������������ͨ�򶫱�����\n"NOR);
		me->set_temp("zangbei/desert_oasis",1);
		return 1;
	}
	tell_object(me,"æ���˰��죬ɳ��������Ȼ��ɳ�ӣ���ããɳ�����������ڿ�ûʲô�á�\n");
	me->start_busy(1);
	return 1;
}


int do_go(string arg) {
	object room;
	object me = this_player();
	if (arg == "west")
	if(me->query_temp("zangbei/����_�����ͱ�") || !random(30)) {
		room = find_object(__DIR__"yangguan1");
   		if(!objectp(room)) room=load_object(__DIR__"yangguan1");
      		message("vision", me->name()+"�����뿪��\n", environment(me),me );
   		me->move(room);
   		message("vision", me->name()+"���˹�����\n", environment(me),me );
   		return 1;
   	}	
	if (arg == "east") {
		tell_object(me,YEL"��������ȥ���ƺ��ֻص���ԭ�أ����Ҳ���ˮԴ������ἢ�ʶ����ġ�\n"NOR);
		return 0;
	}
	if (arg!="northeast")	return 0;
	if (!this_player()->query_temp("zangbei/desert_oasis")) {
		tell_object(this_player(),"������˼�Ȧ�������Լ��ֻص���ԭ�ء�\n");
		return 1;
	}
	message("vision",this_player()->name()+"��ǰ��ȥ����ʧ��ɳ��󲻼��ˡ�\n",this_object(),this_player());
	tell_object(this_player(),"������ʪ���������򶫱�����Ѱȥ��\n");
	tell_object(this_player(),HIG"������������ǰ��Ȼ������һƬ��ɫ��\n"NOR);
	room = find_object(__DIR__"d_oasis");
	if (!room) room = load_object(__DIR__"d_oasis");
	this_player()->move(room);
	return 1;
}
