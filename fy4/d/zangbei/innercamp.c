inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "����");
        set("long", @LONG
���ʺ�С���ʽ����������������ģ�ֻ�ڶ�����һ��ͨ����С�ף��м�������
����һ��ʮ���������ͯ����ǰ����һ�����裬�����Ǽ�����ɵ���ͷ��һ������
��ˮ��Сͯ����Ѫ���У��Ѿ�������ˡ�
LONG
        );
        set("exits", ([ 
	  	"south" : __DIR__"camp",
			]));
	set("objects", ([
		__DIR__"npc/sima" : 1,
	]));
	set("indoor","eren");
        set("coor/x",-440);
	set("coor/y",625);
	set("coor/z",0);
	set("map","zbeast");
	setup();
}

void init() {
	
	add_action("do_loose", "loose");
}

int do_loose(string arg){
	object me,ob;
	int i;
	me=this_player();
	ob=this_object();
	if (!arg && arg!="˾��С��"&& arg!="sima") {
		tell_object(me,"�����ʲô��\n");
		return 1;
	}
	if (!ob=present("sima",this_object())) {
		tell_object(me,"����û������ˡ�\n");
		return 1;
	}
	if (ob->query("loose")) {
		tell_object(me,"���Ѿ����⿪�ˡ�\n");
		return 1;
	}
	message_vision(YEL"
$N���ֽ�˾��С�̴������Ͻ���������
	
˾��С�̻����ػ����ڵ��ϣ����й��๾���ð��Ѫ�ݡ�

˾��С�̶϶�������˵��лл�������ҡ���һֱ��Ϊ�Ҹ����Ǹ�Ӣ�ۣ�
һֱϣ���ҳ������������һ�����ˣ�û�뵽�����������Ľ����"NOR,me);

	if (ob->query("poisoned"))
	message_vision(YEL"	
�����������Ҹ������µĶϳ�˿�����߱�����\n\n"NOR, me);

	message_vision(YEL"
	
�����ˣ���ҲҪ���ˣ����޾��˽��ˡ�

˾��С��������˵���ҡ���֪��һ�����ܣ��ǡ��Ƕ��˴���ʵ��
��ʵû�С�û�С������ǣ���������

��������������\n\n"NOR,ob);
	
	ob->die();
	set("poisoned",0);
	
	if (REWARD_D->riddle_check(me,"˾��С��")==4)
		REWARD_D->riddle_done(me,"˾��С��", 30, 1);	
	
	QUESTS_D->special_reward(me,"˾��С��");
	return 1;
}
