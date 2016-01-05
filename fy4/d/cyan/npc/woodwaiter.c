// waiter.c
#include <ansi.h>
inherit SMART_NPC;
inherit F_VENDOR;

int d_1();

void create()
{
	object weapon;
    set_name("СС����", ({ "spirit" }) );
	set("gender", "����" );
	set("age", 2);
//	set("price_modifier",10000);
	set("combat_exp", 0);
	set("attitude", "friendly");
	set("vendor_goods", ([
	"/obj/generate/commonweapon/70/axe":20,
	"/obj/generate/commonweapon/70/blade":20,
	"/obj/generate/commonweapon/70/fist":20,
	"/obj/generate/commonweapon/70/hammer":20,
	"/obj/generate/commonweapon/70/spear":20,
	"/obj/generate/commonweapon/70/staff":20,
	"/obj/generate/commonweapon/70/sword":20,
	"/obj/generate/commonweapon/70/throwing":20,
	"/obj/generate/commonweapon/70/whip":20,
	]) );
	
	set("inquiry",([
		"����":     "�����˼���ǧ���ˣ��粻���Ƕ����ˡ�\n",
		"stone":	"�����˼���ǧ���ˣ��粻���Ƕ����ˡ�\n",
		"�������":  "������䣬���������ʯ���������ǿ�ѽ��\n",
		"jade":     "������䣬���������ʯ���������ǿ�ѽ��\n",
        "��ʮ��":	"��ԭ�������µĵ���ʮ����С�ݣ������Ѿ��������ʮ���ˡ�������\n",
        "emerald":  "������䣬���������ʯ���������ǿ�ѽ��\n",
        "����":		"�����������������ǧ��һ��������ǧ��һ�������ȵļ�ô��\n",
        "tree":		"�����������������ǧ��һ��������ǧ��һ�������ȵļ�ô��\n",
        "��":		"�����������������ǧ��һ��������ǧ��һ�������ȵļ�ô��\n",
         "˾��ժ��":	"actionСС���˳����������ǡ��ǰ��˵��ġ���Ҫȥ׷Ѱ��\n",
        
        "С��":		(: d_1() :),
        "grass":	(: d_1() :),
        "��":		(: d_1() :),
        "��ʯͷ":	"actionСС����ҧѽ�г���ʹ��״��",	
		"���̲�": "����һ�ּ�����"YEL"ҩ��"CYN"���Һ������ҵ�һ�����ڼ��ſڣ��ϸ���ȴ���������ˡ�\n",
		"ҩ��": "ҩ���㶼������ȥ�ʴ�򣬱������ҡ�\n",
	]) );


	setup();

}


void init()
{	
	object ob;

	::init();
	add_action("do_vendor_list", "list");
}

int do_w()
{
//return notify_fail("СС����ҡͷ��������ȫ�����ˣ��´����硣\n");
}

int d_1()
{
	object me = this_player();
	if (REWARD_D->riddle_check(me,"�������") != 2
		&& REWARD_D->riddle_check(me,"�������") != 3)
	{
		message_vision("СС���˵�����ɽ���ﵽ���ǲݣ����ܴ�\n",me);
		return 1;
	}
	ccommand("hmm");
	ccommand("say ����˵����ǰ��С�ݰ����ϸ�����һ����ʯͷ�����ˣ�");
	ccommand("say ����ʯͷ��Ȼ����ʲô�ö����������Ȼ���"HIG"���̲�"NOR CYN"����");
	REWARD_D->riddle_set(me,"�������",3);
	return 1;
}

int give_me_it(object me)
{
	object item;

	item = new("/obj/specials/stone/gstone");
	if (objectp(item)){
		message_vision(HIW"һ�龧Ө��͸���������$N���С�\n"NOR, me);
    	item->move(me);
 //   	me->set("stone_mark/gstone", 1);
    	log_file("riddle/IMBUE_LOG",
		sprintf("%s(%s) �õ�������䡣 %s \n",
			me->name(1), geteuid(me), ctime(time()) ));
    }
	return 1;
}



int accept_object(object who, object ob)
{
	object me = who;
	if (REWARD_D->riddle_check(me,"�������") != 9)
	{
		ccommand("emote �ӹ�"+ob->name()+"����Ҳ���������ֶ�����ߵ�̳̳�޹��\n");
		return 1;
	}
	if (ob->query("name") != HIG"���̲�"NOR || ob->query("real_flower") != 3)
	{
		ccommand("emote �ӹ�"+ob->name()+"����Ҳ���������ֶ�����ߵ�̳̳�޹��\n");
		return 1;
	}
	ccommand("ack");
	ccommand("emote ����ͷ������һ����ɫ��Сʯ�ӣ����ֶ���"+who->name()+"��");
	give_me_it(me);
	ccommand("emote ����"HIG"���̲�"NOR CYN"������������С��������Ե�һ��С���С�");
	REWARD_D->riddle_done(who,"�������",200,1);
	return 1;
}