inherit NPC;
#include <ansi.h>
inherit F_MASTER;

int s_quest();
int give_reward(object who,mapping quest);
int time_period(int timep, object me);
int wait_period(int timep, object me);
int newbie_quest();
string sysmsg;

void create() {

    set_name(HIY"�������"NOR, ({ "tian ji","tianji"}) );
    set("gender", "����");
    set("long", "
�������������ף��׷�ͯ�ա��ڱ�������������һ�������Ϲ٣�С��
֮�ϣ�����������а�����¶��ɰ��������������\n");
	set("attitude", "peaceful");
	create_family("��ң��", 1, "��ʦ");
	set("title", "����Ұ��");
	set("class","tianji");
	
	set("age", 99);
	set("str", 2600);
	set("NO_KILL",1);
	
	set("inquiry",	([
		"�㱨":		(: s_quest() :),
		"�ر�":		(: s_quest() :),
	]));
		
	set("chat_chance", 1);
	set("chat_msg", ({ 
		"������������̳��˼��ڡ�������\n"
	}));
	
	set("combat_exp", 20000000);
	set("score", 200000);
	
	set_skill("unarmed", 200);
	set_skill("force", 200);
	set_skill("iron-cloth", 200);
	set_skill("yiqiforce", 300);
	set_skill("dagger",200);
	
	map_skill("iron-cloth", "yiqiforce");
	map_skill("force", "yiqiforce");
	map_skill("unarmed", "yiqiforce");
	
	
	setup();
	carry_object(__DIR__"obj/jade-cloth")->wear();
	carry_object(__DIR__"obj/hanyan")->wield();
}

int s_quest(){
	object me = this_player();
	object ob = this_object();
	
	if (me->is_fighting())	return notify_fail("��������æ��\n");
		
	if (me->query("quest/quest") == "��������"){
		if (time() - me->query("quest_time") > 290) {
			tell_object(me,"������˲�����˵�����������ͷ������ʱ��̫���֡�\n");
			tell_object(me,"��û���ڹ涨��ʱ�������������˵�������������Զ�ȡ���ˡ�\n");
			me->delete("quest");				// both are required
			me->delete("annie_quest");
			me ->delete_temp("annie_quest");		
			me->delete_temp("quest_number");
			me->delete("cont_quest");
			me->delete_temp("luyu");
			return 1;
		}
		if (time()-me->query("quest_time")< 180) {
			tell_object(me,"�������˵���Ȳ���������������ߡ�������\n");
			message_vision("�������һ���֣�$N���Ƽ���ط��˳�ȥ��\n"NOR, me);
			if (me->query("gender")=="����")
				me->move("/d/qianjin/hotel2");
			else
				me->move("/d/fugui/kefang");
			tell_object(me,"���㻹��Ҫ"+ chinese_number(me->query("quest_time")+180-time())+
				"���Ӳ�������������\n");
			return 1;
		}
		tell_object(me,"�������˵�����������ݽ�ϣ����ܹ����ٹ���\n");
		if ( QUESTS_D->verify_quest(me,"��������"))
			QUESTS_D->special_reward(me,"��������");
		return 1;
	}
	
	command("dapp " + me->query("id"));
	return 1;
}


int accept_fight(object me) {
	command("say �����ɹ󣡲�Ҫ��Ѱ��·��");
	return 0;
}


void init() {
	add_action("give_quest", "quest");
	add_action("q_return", "qreturn");
}


int accept_object(object who, object ob) {
	if (QUESTS_D->accept_quest_object(who, ob, this_object()))	{
		return 1;	
	}
	else
	{	
			tell_object(who, "�������Ц������˵����Т��үү�Ͷ��үү�ɻ\n");
			return 0;
	}
}

int q_return(string arg){
	object me,box;
	mapping quest,items;
	string name,*dir;
	int num, index, i;
	
	me = this_player();

	if (!(box = present("treasure box", me)))
		return notify_fail("������ֻ��Я��������е��˲���ʹ�á�\n");
	
	if (!box->query("quest_box"))
		return notify_fail("������ֻ��Я��������е��˲���ʹ�á�\n");
	
//	items = box->item_list();
	
	items = me->query_qitems();
	
	if (!items || sizeof(items)<1)
		return notify_fail("�����������ǿյġ�\n");
	
	if (arg)
		name = arg;
	else if (mapp(quest = me->query("quest")))
		name = quest["quest"];
	else
		return notify_fail("���뽻����һ���ѣ�������Ʒ��\n");
	
	if (!name)
		return notify_fail("���뽻����һ���ѣ�������Ʒ��\n");
		
	if (box->query("timer/op") + 2> time()) {
		write("Ϊ��ʡϵͳ��Դ��������������������������ȴ������ӡ�\n");
		return 1;
	}
	box->set("timer/op", time());
	
	arg = box->replace_color(name);
	num = sizeof(items);
	dir = keys(items);
	index = member_array(arg, dir);
	if (index == -1) {		// ��һ������ɫ��ƥ��
		for (i= 0; i<num; i++) {
			if ( arg == "/feature/nada"->ngstr(dir[i])) {
				index = i;
				break;
			}
		}
	}

	if (index==-1)
		return notify_fail("������������û��"+arg+"�����Ʒ��
����ʽ�����������������Ʒ����\n");

	if (QUESTS_D->accept_quest_object(me, dir[index], this_object())){	
		box->do_qqdiscard(dir[index],me,0);
		return 1;							
	}
	tell_object(me, "�������˵�����������������Ҫ�ġ�\n");
	return 1;	
}

int give_quest(string arg) {
	
	int gold,rt,gr, level;
	object who;
	
	who = this_player();
//	�����Ǹ��ս����ģ�������ģ�����䡡���������	
	if (REWARD_D->riddle_check(this_player(),"��������") 
		&& !REWARD_D->check_m_success(this_player(),"��������")) {
		newbie_quest();
		return 1;
	}
	
	gold  = this_player()->query("deposit")/100;
	if ((arg == "cancel" || arg == "fail") && this_player()->query("quest"))
	{
			
		// ����ȡ���ࣺ
		rt = this_player()->query("quest")["cancel"];
		if (rt == -1)
		{
			tell_object(this_player(),"��ô��Ҫ��������ô��ȡ���أ�����\n");
			return 1;
		}
		
		level = F_LEVEL->get_level( who->query("combat_exp"));
		
		if (level >= 80)		gr = 200;		// 4M
		else if (level >=50)	gr = 150;		// 2M
		else if (level >=30) 	gr = 100;		// 1M
		else if (level >=10)	gr = 50;		
		else 					gr = 25;
		
		if (arg == "cancel")		gr = gr*2;

/*		if (rt>0)
			gr = gr + gr*rt/100;	*/
			
		// this is for quest optimization
		if (who->query("timer/quest_cancel") + 300 > time())
		{
			who->add("marks/quest_cancel",1);
		}
		who->set("timer/quest_cancel",time());
        
        if (gold <gr)
		{
			tell_object(this_player(),"�����������"+chinese_number(gr)+"�����ӡ�\n");
			return 1;
		}
        
        who->add("deposit", -gr*100);
        
        if ( arg == "cancel")
        {
        	tell_object(who, YEL"������˵��˵������"+chinese_number(gr)+"�������ֺǺǵ�˵����Ȼ����������ͻ�һ���ɡ�
�������������ϻ���"+chinese_number(gold-gr)+"�����ӣ�\n"NOR);
		}	
		else
		{
			//����С��12���ӣ�quest fail�Ժ�Ҫ��3���Ӳ���Ҫ���� 
			if (time() - who->query("quest_time") < 720){
				who->set("next_time", time() + 180);
				tell_object(who, YEL"�����������üͷ˵����Ҳ��ǿ�����ѣ�����"
				+ chinese_number(gr) +"��������ȥ��Ϣ��Ϣ������������ɡ�
				�������������ϻ���"+chinese_number(gold-gr)+"�����ӣ�\n"NOR);
			} else 
			//���˴���12���ӣ�quest failҲֱ��ȡ��������Ҫ�ٵ�3����
				tell_object(who, YEL"�����������üͷ˵������¶��첻�ã����������������ô�ã�
��Т����" + chinese_number(gr) +"�����ӵķ��ϣ����㻻������ɡ�
�������������ϻ���"+chinese_number(gold-gr)+"�����ӣ�\n"NOR);
		}		
		who->delete("quest");				// both are required
		who->delete("annie_quest");	
		who->delete_temp("annie_quest");	
		who->delete_temp("luyu");
		who->delete_temp("quest_number");
		who->delete("cont_quest");
		return 1;
	}
	
	return QUESTS_D->give_quest(this_player(), 
			([	"name" : this_object()->name(),
                                "employer" : "�������" ])
			);	
}


void attempt_apprentice(object me) {
	switch(random(4)) {
		case 0:
			message_vision("$N��$nЦ�ʵ���ʲô�ǡ��Ľ�����\n", this_object(),me);
			break;
		case 1:
			message_vision("$N��$nЦ�ʵ���ʲô�ǡ��в������Ҳ�������һ�������ȶ�����\n", this_object(),me);	
			break;
		case 2:
			message_vision("$N��$nЦ�ʵ��������Σ����Ρ���ʲô��\n", this_object(),me);		
			break;
		case 3:
			message_vision("$N��$nЦ�ʵ�����ѧ����߾�����ʲô��\n", this_object(),me);
			break;
	}
}

int attack()
{
	object opponent;
	opponent = select_opponent();
	if (userp(opponent)) {
		if (random(10)) {
			set_temp("last_opponent", opponent);
			command("say �����ɹ󣬲�Ҫ��Ѱ��·��");
			this_object()->remove_all_killer();
			return 1;
		} else {
			command("say ��֪����Ķ�����ȥ���ɡ�");
			COMBAT_D->do_attack(this_object(), opponent, query_temp("weapon"));
			return 1;
		}
	} else if(objectp(opponent)) {
		COMBAT_D->fight(this_object(), opponent);
		return 1;
	} else
		return 0;
	
}

void unconcious()
{
        int gin,kee,sen;
        gin =(int)query("max_gin");
        kee =(int)query("max_kee");
        sen =(int)query("max_sen");
        set("eff_kee",kee);set("kee",kee);
        set("eff_gin",gin);set("gin",gin);
        set("eff_sen",sen);set("sen",sen);
        return ;

}

void die()
{
        int gin,kee,sen;
        gin =(int)query("max_gin");
        kee =(int)query("max_kee");
        sen =(int)query("max_sen");
        set("eff_kee",kee);set("kee",kee);
        set("eff_gin",gin);set("gin",gin);
        set("eff_sen",sen);set("sen",sen);
        return ;

}

///	newbie ���Σ�����������򡡣�������

int newbie_quest() {

	object me,ob,silver;
	
	me=this_player();
	ob=this_object();
	
	switch (me->query_temp("marks/newbie_quest")){
		case 1: tell_object(me,WHT"
�������˵������ȥ�ݼ���ʯ����ô�������ƶ����ŵ����·�����Ͼ����䵱ɽ����\n\n"NOR);
			return 1;
		case 2: if (me->query_skill("literate",1) < 1) {
				tell_object(me,WHT"
�������˵����Ҫѧ����ֲ�ʶ��ô�У������Ǽ��ڽֹ�Ժ���ʵ��Ƕ�ȥ
ѧ���������Ұɣ�learn literate from kao guan with 1��\n"NOR);
			return 1;
			}  		
			break;
		case 3: tell_object(me,WHT"
�������˵������ȥ�ݼ�����ף��ô�����ڹ���Ĵ����¡���\n\n"NOR); 
			return 1;
		default:
	}

	if (REWARD_D->riddle_check(me,"��������")==4)
	{
		tell_object(me,WHT"
�������˵����ɳ��������Ҹ���ã����������ôһ������ɵġ�������
һ�ˣ���Ӧ��������Ϥ��ͼ�Ƿǳ���Ҫ�ģ�����������֮�࣬Ҫ��������
�ˣ��࿴���������ߣ�����ĵ�ͼ����"HIR"����𡡣����"NOR+WHT"

������Ҫѧ�Ķ���̫���ˣ�һʱ������Ҳ����˵������㵽��������Щ
�ڣ�����ļ��ﶼ����ϸ˵����

��������������ͷ˵���������ʦ���ܶ࣬���������Լ��Ŀ��ҹ���
ȥ��һ���ʺ���İɡ����һʱ�������ʦ�����ǽ�ʨ�ھֵĲ����Ǹ���
������ˣ�ֻҪ����"HIG"����"NOR+WHT"�����ͻ�����ѧ�㹦�����������ӣ���������
���а����ģ�����Ҳ����ʲô��������ѧ��

���ǵ��������̿�����Щ������
�ϳǷ��Ʋ������ϲ÷��Ƕ���Щ����ֵֹĺ��·���
���ǵ�ǧ�����̺��Ϲ�Ǯׯ�����������ʹ�Ǯ�ĵط���
���Ƕ�ǧ��ľ������ר�ų��۸����ֵ��书�����鼮��
��������˿��Ե�ǧ��¥�����������������ȥϴ�裬��ϴϴ�Ϳ��Իָ���

����������Լ���������Quest�������ʵ���겻��Ҳû��ϵ�����Է���
��Quest fail���ȴ�3���ӣ�����ȡ������Quest cancel������ȴ�����
��Ȼ����Ҳ������˻��Ͽ۵������ѡ�

����еģ��������֪����ô��ɣ������������𡡣��������
�����ѡ����Ӧ�ĵ�������������ϸ�Ľ��ܣ����߿����ڣ������
����Ƶ����ѯ�ʣ�������������˻��Ǻܶ�ġ�

Ҫ������������ǵõ��������ĸ�ȥ��һ��"HIR"�������"NOR+WHT"��������Ƿ��Ƶ�
һ���������Ƕ��������֪����ʲô�ˡ����ӹ㳡��w w n �㵽�ˣ�

������һ�����ӣ���������·�ɡ�ʦ������ţ������������ڽ�����Ҫ
�㽻���ѣ��������ơ���������ʣ��պ�سɴ�����

"NOR);
		silver = new("/obj/money/coin_lock");
		silver->set_amount(1);	
		if (!silver->move(me))
			destruct(silver);
		
		REWARD_D->riddle_done(me,"��������",200,1);
		return 1;
	}

	if (REWARD_D->riddle_check(me,"��������")==3)
	{	
		tell_object(me,WHT"
���������˵����������ȥ�ݼ�һ�¹�������±�������ף����������
ʲô�������ˣ�����ĸ�����ÿ���������Ƕ�ȥ�ȹ��衣������
��������Դӳ������ߣ����ߵ����Ƿ�����վ���ﴦ������ԽɳĮ����
�����Ѿ����㸶�ˡ���\n"NOR);
		me->set_temp("marks/wangfeng",1);
		me->set_temp("marks/newbie_quest",3);
		return 1;
	}

	if (REWARD_D->riddle_check(me,"��������")==2)
	{		
		tell_object(me,WHT"
����������������ͷ˵�����ã��ã�����������������˼Ҹɻ����
����߽���������ʦ���Ż���㹦�򡣲�����Ҫѧ�书��ʶ�ֿɲ��С�������\n"NOR);
		if (me->query_skill("literate",1)>=1) {
			tell_object(me,WHT"\n��ѧ���˶���ʶ�֣���Ľ��������ḻ�ˣ�\n"NOR);
			me->add("combat_exp",500);
			tell_object(me,YEL"
�ţ��������־����Ѿ��е��ĵ��ˣ����ڽֶ�ǧ���Ƕ��������������
�鼮���пտ���ȥ����һ�¡���ס�������Խ�࣬�˾�Խ������ѧ�书��
���ؼ������°빦������ʹ������skills���Բ鿴���Լ�ѧ���ļ��ܣ�

���������˵����������ȥ�ݼ�һ�¹�������±�������ף����������
ʲô�������ˣ�����ĸ�����ÿ���������Ƕ�ȥ�ȹ��裮����
����������Դ����ϴӳ������ߣ����ߵ����Ƿ�����վ���紦������Խ
ɳĮ���������Ѿ����㸶�ˡ���
�����Ƶĵط��ܴ������������է�����ǵ���ʱʹ�ã���ָ�ͬʱ
Ҳ���Բο�help newbie�еķ��Ƶ���ƪ���õ�һЩ��ʾ����\n"NOR);
			me->set_temp("marks/wangfeng",1);
			REWARD_D->riddle_set(me,"��������",3);
			me->set_temp("marks/newbie_quest",3);
			return 1;
		} else {
			tell_object(me,WHT"
���ǹ�Ժ��Ŀ������ʵ����ڴ������־�����ȥѧһ����ٻ������ң�
learn literate from kao guan with 1\n\n"NOR);
			me->set_temp("marks/newbie_quest",2);
			return 1;
		}
	}

	
	if (REWARD_D->riddle_check(me,"��������")==1)
	{
		tell_object(me,WHT"
������˺��Ƶؿ�����˵�����ǵ�һ�ε����Ƴǰɣ�СС��;��ܳ�����
�������ˣ���־���������˵��Ҳ���ѣ����������Щ�ϼһ���ţ����
�棬�׻�˵����������ǰ�ˣ�ǰ������ɳ̲�ϣ�ֻҪ����¿๦���г�һ
�տ����Ǿ��񿳹��в�һ������������

�������˵�������콫��������˹��Ҳ�����ȿ����ǣ�������־��������
���¿�ͷ�ѣ����Ϊ���֣���Ҫ��С������ ---- Ҳ���Ǹ������˼�����
�ȶ��������ɣ��Һþ�û�����䵱ʯ�������ˣ�����ȥ�����ʸ��á�����
�ƶ����ŵ����·���ϣ������䵱ɽ�����ҵ�������\n\n"NOR);
		me->set_temp("marks/newbie_quest",1);
		return 1;
	}
	return 1;
}


void reset(){
	if (environment())
		command("chat [1;31m������ӿ����ر�ɫ�����︴�գ�Ӣ�۱�����[0;32m");
}
