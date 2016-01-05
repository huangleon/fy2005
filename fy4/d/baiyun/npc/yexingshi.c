inherit SMART_NPC;
#include <ansi.h>

int leave();

int annie_drug()
{
	object me = this_player();
	
	int i;
	i = random(3)+1;


	if (me->query_temp("annie/find_herb/����") 
		&& me->query_temp("annie/find_herb/������") 
		&& me->query_temp("annie/find_herb/��С��") 
		&& me->query_temp("annie/find_herb/����") 
		&& me->query_temp("annie/find_herb/����ѩ") 
		&& me->query_temp("annie/find_herb/Ҷ��ʿ")	)
	{
		message_vision(query("name")+"�ɵ�����Ҷ���֪�����ǡ����ǡ���\n",me);
		message_vision(query("name")+"ͻ��һ��ͷЦ�����㿴������ԣ���������÷��������\n",me);
		return 1;
	}

	if (me->query_temp("annie/find_herb/Ҷ��ʿ"))
	{
		message_vision(query("name")+"ҡͷ������ίʵ����������\n",me);
		return 1;
	}
	message_vision(query("name")+"�����������̲ݣ����̲ݣ�����ҽ���ϲ�û���ص���ζҩ�İ���\n",me);

	message_vision(query("name")+"˵����"+"������ҽ������֪���䣬��˵��Զ��ֶ��������ɽ���㲻����ȥ����������\n",me);
	me->set_temp("annie/find_herb/Ҷ��ʿ",1);
	return 1;
}


void create()
{
        set_name("Ҷ��ʿ", ({ "ye xingshi", "ye"}) );
        set("nickname", CYN "ҽ��"NOR);
		set("vendetta_mark","shaolin");
		set("gender", "����" );
		set("age", 44);
		set("attitude","friendly");
	

		set("long",
	        "Ҷ��ʿ���������ȴ�˧��Ψ���׼ҵ��ӣ�Ҳ�ǽ����о���ʢ�����Ĵ���ҽ֮����\nҽ�����������¹��ϣ�����Ϊ��ҽ�ɡ���\n"
		);
        set("inquiry",  ([
				"���ν���" :  (: leave :),
				"����" :  (: leave :),
				"help" :  (: leave :),
        	"���̲�" : 	(: annie_drug :),
        ]) );
	set("chat_chance", 1);
	set("chat_msg", ({
        name()+"���۳���̾�����޹�Ҷ�³��ڴ˳��ӣ���ȷ�Ǹ��ɾ�������ڡ�\n",
        "Ҷ��ʿ�������ο�Ц����Ҷ������ΰ��ҡ��롱�����Ƴǣ���֪����Ϊ�Σ�\n",
        "Ҷ��ʿ���˷����С��Ƶ��ھ�������ü����Ҷ����ü��΢����ڣ��ѵ����˶���\n",
        }) );
	
    set("combat_exp", 400000);
	
	auto_npc_setup("wang",100,70,0,"/obj/weapon/","fighter_w","taiji",1);
	setup();
    carry_object("/obj/armor/cloth")->wear();
}


int leave()
{
	object room = load_object("/d/baiyun/dragonplace");
	if (REWARD_D->riddle_check(this_player(),"��ͼһ��") !=5)
		return 0;
	message_vision("$N������Ҿ����֮����ȥ����\n"NOR, this_player());
	message_vision("$N������ɫ������ˡҶĳ���ܣ������и�ϵ̫������ƽ��ɵļ��¡�����\n"NOR, this_object());
	message_vision("$Nҡ��ҡͷ�������ǵ��Ϻ��������ʲô����֪����ֻ֪������Щ���ҵ�������Ϊ���ġ�\n"NOR, this_object());
	REWARD_D->riddle_set(this_player(),"��ͼһ��",6);

	return 1;
}
