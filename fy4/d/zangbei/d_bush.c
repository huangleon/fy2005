#include <ansi.h>

inherit ROOM;

string *user_channel;

void create()
{
        set("short", "С����");
        set("long", @LONG
��е���Ҷ�䣬��ʱ��������Ц�����������Ȿ�ǻ��ֵ�Ц����������п�
����Ĵ�ɳĮ�У�һ���챻�������˶������Ц��ȴ��ʲ�ᶼҪ���ؿɲ�������
���������еĻþ���ħ�����������������Ҷ��ѵ�����������Щר���ջ�
�¶�������ȥ���ɵĳ���Ů����
LONG
        );
        set("exits", ([ 
	  	"south": __DIR__"d_oasis",
		]));
	set("objects", ([
		
	]));
	set("item_desc",([
		
	]));
        set("outdoors", "zangbei");
        set("coor/x",-70);
	set("coor/y",320);
	set("coor/z",0);
	set("map","zbeast");
	setup();
}

void init(){
	add_action("do_listen","listen");
	add_action("do_look","look");
	add_action("do_jump","jump");	
}

int do_listen(){
	tell_object(this_player(),"��ʱ��������Ц������Ҷ��ͷ��������ʹ���̲�ס��ȥ����һ����\n");
	return 1;
}

string *event1_msg=	({
	
	"��ï�ܵ�ľҶ������ȥ���������Ƽ�һ�����˶��ģ������Ի�
���˼�ֱ�޷����ŵľ���",
	
	"С�����ԣ��˿�Χ�ż���ɴᣣ��������Ǳߵ����ߡ�������",
	
	"һ�������ĳ�����Ů�����ڳ�����ԡ��",
	
	"�������ĸ�������Ů���е���������ԡ���е�����ɴ�£��е�����ԡɴ��",

	"��Ů��վ�ڳ����߽�Ц�ţ���������ˮ��ˮ��Ҳ���Ž�⡣",
	
	"		ͻȻ",
	
	"����Ů���ĵ��۲�����Ȼ�������һת��",

});


void event1(object me, int count)
{
	if (environment(me)!=this_object() || me->is_fighting()) {
		return;
	}
	
	tell_object(me,CYN"\n"+event1_msg[count]+"\n"NOR);
	if(++count==sizeof(event1_msg))
	{
		tell_object(me,HIR"\n���ˣ��㱻�����ˣ�����\n\n"NOR);
		tell_object(me,WHT"�������ߣ�jump away���أ������������߹�ȥ��jump down����\n"NOR);
		me->stop_busy();
		me->set_temp("zanbei/����_jump",1);
		return;
	}
	else call_out("event1",1,me,count);
	return ;
}


int do_look(string arg){
	object me;
	if (arg == "tree" || arg == "��" || arg == "��ľ" || arg== "��Ҷ" || arg=="leaves" || arg == "leaf") {
		me = this_player();
		if (me->query("zangbei/����_͵��ʧ��")+ 3600 > time()
			|| me->query("zangbei/����_����ʧ��")+ 3600 > time()) {
			tell_object(me,"�㲻�Ǹո��Ϲ����������ô��Ҫ��������ˣ�\n");
			return 1;
		}
		message_vision("$N����������֦���������Ǳ���ȥ��\n",me);
		me->start_busy(8);
		call_out("event1",1,me,0);
		return 1;
	}
	return 0;
}

int do_jump(string arg) {
	object me, room;
	me = this_player();

	if (!me->query_temp("zanbei/����_jump"))
		return 0;
	
	if (!arg || (arg!= "away" && arg!="down")){
		return notify_fail("������ô����\n");
	}
	
	
	if (me->is_busy())
		return notify_fail("��������æ��\n");
	
	if (arg == "away") {
		tell_object(me,YEL"�㰵��һ�����²���Ͻ�һ���̵��������㿪�ˡ�\n"NOR);
		me->delete_temp("zanbei/����_jump");
		return 1;
	}
	if (arg == "down") {
		tell_object(me,YEL"
��̾�˿�������Ц��Ծ����������һ���ӣ���ֱû�бȴ˿̸��������ε�
ʱ���ˡ����㲻���ӣ�ֻ��Ӳ��ͷƤ�߹�ȥ��\n"NOR);
		if (!room = find_object(__DIR__"d_pond")) room = load_object(__DIR__"d_pond");
		me->move(__DIR__"d_pond");
		me->start_busy(8);
		me->delete_temp("zanbei/����_jump");
		room->event2(me,0);
	}
	return 1;
}
	
	
