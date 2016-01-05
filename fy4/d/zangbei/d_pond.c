#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "С����");
        set("long", @LONG
��ï�ܵ�ľҶ������ȥ�������һ�����˶��ģ������Ի����˼�ֱ�޷�����
�ľ���С�����ԣ��˿�Χ�ż���ɴᣣ��������Ǳߵ����ߣ�һ�������ĳ�����Ů��
���ڳ�����ԡ���������ĸ�������Ů���е���������ԡ���е�����ɴ�£��е���
��ԡɴ��վ�ڳ����߽�Ц�š����ǻ�������ˮ��ˮ��Ҳ���Ž�⡣
LONG
        );
        set("exits", ([ 
	  	
	  	"south": __DIR__"d_bush",
			]));
	set("objects", ([
		__DIR__"npc/princess":	1,
	]));
	set("item_desc",([
		
	]));
	set("resource/water",1);
        set("liquid", ([
        "container": "С����",
        "name":		"С����ˮ",
     ]));
        	
    set("outdoors", "zangbei");
    set("coor/x",-70);
	set("coor/y",330);
	set("coor/z",0);
	set("map","zbeast");
	setup();
}

string *event2_msg=	({
	
	"��Ů�������³������˼��ۣ����ѳ�����ŭ���������ƺ������΢�ͻ���һЩ��",
	
	"��Ů����������㵨�ӵ���С����Ȼû���ӡ�",
	
	"���Ц��������������⣬�Ѿ����ǲ�������Ҫ���ߣ���Ǹ������ˣ�",

	"��Ů�۲��������������ᣬ�����������ģ�",

	"��������ǡ�",

	"����ŮĿ������Ц�⣬����������������ϴ����������Ǹ��е�ʶ���ˡ�",
	
	"��Ůһ���ۣ�����Ҳ���ҹ�����͵����",

});


void init(){
	add_action("do_answer","answer");
}

void event2(object me, int count)
{
	object room;
	
	if (environment(me)!=this_object() || me->is_fighting()) {
		return;
	}
	tell_object(me,CYN"\n"+event2_msg[count]+"\n"NOR);
	if(++count==sizeof(event2_msg))
	{
		tell_object(me,WHT"\n�㰵��˼���������֪��������������ô����answer yes/no����\n"NOR);
		me->set_temp("zangbei/pond_talk",1);	
		return;
	}
	else call_out("event2",1,me,count);
	return ;
}

		


int do_answer(string arg){
	object me,room;
	me = this_player();
	room = find_object(__DIR__"d_tent");
	if (!room) room = load_object(__DIR__"d_tent");
	
	if (!me->query_temp("zangbei/pond_talk")) return 0;
	if (!arg || (arg!= "yes" && arg!="no")){
		return notify_fail("answer yes or no\n");
	}
	
	if (arg == "no") {
		tell_object(me,YEL"\n����ɫ�����������򲻸ң�\n\n"NOR);
		me->set("zangbei/����_͵��ʧ��",time());
		tell_object(me,CYN"��Ů΢΢��Ц��һ���֣���ֻ����һ�ɴ���Ϯ�������Ƽ���ط��˳�������\n\n"NOR);
	}
	else {
		tell_object(me,YEL"
����������Σ�����������������֪������������������ļ��˳�ԡ����֪��
������һ��û����ɴ᣸��𡭡�������Ȼ˫�Ⱦ�ϣ�˵������ҲҪ�����ġ���\n"NOR);

	tell_object(me,CYN"\n
��Ů�������㣬�������ã����Ϻ���¶���������Ц�ݣ��������벻��Ҳ�и�
˵�滰�����أ�Ҳ���Ҳ���ˡ������Ҫ������Ϊ�ϱ�������ȴҪ�������
���Ӵ�֮�⣬�ǲ��ǻ��б�ı����ˡ���

������������������ͷ����ת��������㷽�ż�δ���ߣ����ڿɸҵ���������
��ô����

��Ů΢΢��Ц��һ���֣���ֻ����һ�ɴ���Ϯ�������Ƽ���ط��˳�������\n\n"NOR);

		me->set("zangbei/����_͵���ɹ�",1);
	}
	message("vision",HIG"ֻ����Ҷˢ����һ���Ҷ���һ����Ӱ���˳�����\n\n"NOR,room);
	me->move(__DIR__"d_tent");
	me->delete_temp("zangbei/pond_talk");
	me->stop_busy();
	return 1;
}

