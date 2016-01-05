// Sinny-silencer@fy4 workgroup 

#include <ansi.h>
#include <room.h>
inherit DOOR_ROOM;

void create()
{
	set("short", "�һ���");
	set("long", @LONG
����һ���С��С��ľ�ݣ������������һ����ۺ�ɫ�Ļ���Ʈ���ڿ��У����� 
Ҳ����һ���������̺����һ��꣬�����г�����Ũ�صĻ��㣬������֮�У�һ 
�Ƹ��������ǵĵ��������������ڻ����У������У�������С���������ֻ��һ֦ 
�һ�֦б����ľǽ���У���յ����ı������
LONG
	);
	set("no_clean_up", 0);
	set("no_fly",1);
	set("exits",([
		"north" : __DIR__"taoyuan-exit",

	]));
        set("item_desc", ([
        	"�һ�֦":	"
һ֧�һ�֦��֦Ҷӯ�����Σ��һ�������ʣ�һ�ž�Ө��¶���ڻ����������δ�䡣 
����Դ�ǽ�ϰ����Σ�pull��������\n",
        	"branch":	"
һ֧�һ�֦��֦Ҷӯ�����Σ��һ�������ʣ�һ�ž�Ө��¶���ڻ����������δ�䡣 
����Դ�ǽ�ϰ����Σ�pull��������\n",
	]) );
	set("coor/x",-80);
	set("coor/y",-120);
	set("coor/z",-10);
	setup();
//	create_door("north", "door","ľ��", "south", DOOR_CLOSED);
}


void 	init(){
	add_action("do_pull","pull");
}


int	do_pull(string arg){
	
	object me = this_player();
	if (me->is_busy())
		return notify_fail("��������æ�š�\n");
	if (!arg)	return notify_fail("�����ʲô?\n");
	if (arg == "�һ�֦" || arg == "peach branch" || arg=="branch") {
		if (!REWARD_D->riddle_check(me, "�һ���̽��") || present("meihuadao",this_object()))
			return notify_fail(YEL"��ҡ��ҡ�һ�֦��û�з���ʲô�쳣�ĵط���\n"NOR);
		if (this_object()->query("pull_time")+300> time())	// 5���ӳ���һ�Ρ�
			return notify_fail(YEL"��ҡ��ҡ�һ�֦��ʲô����Ҳû�С�\n"NOR);
		message_vision(GRN"\n$N�ߵ�ǽ�ߣ�����ժ��ǽ�ϵ��һ�֦�� \n
�����糣��Ψ���ݶ��������º��װ׵�÷���꣬����һ������$N���ϣ����ϡ�����\n\n"NOR,me);
		me->start_busy(3);
		this_object()->set("pull_time",time());
		call_out("meihua_out",4, me);
		return 1;
	}
	tell_object(me, "���û������������\n");
	return 1;
}


int	meihua_out(object me){
	
	object meihuadao;
	if (!objectp(me) || environment(me)!=this_object())	return 1;
	message_vision( GRN"\n÷�����У�һ������Ϯ���� \n
     			Ʈ��÷�껨���򣬾�֮������չ� \n"+MAG"\n
���ĵ�̾�����У����ж���һ����ɴ֮�ˣ�ֻ��һ˫����¶�˳��������Ǽ�ڽ֮�⡣\n 
÷������̾һ����Ҳ�����ԣ�����Ʈת�У����Ѫɫ��÷������$N��\n\n"NOR,me); 
	meihuadao = new(__DIR__"npc/ty-meihuadao");
	meihuadao ->move(this_object());
	return 1;
}
	
	
	