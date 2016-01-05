#include <ansi.h>
inherit SMART_NPC;
inherit INQUIRY_MSG;

int do_story();
int do_cure();

int annie_drug()
{
	object me = this_player();

	if (me->query_temp("annie/find_herb/����") && me->query_temp("annie/find_herb/������") && me->query_temp("annie/find_herb/��С��") && me->query_temp("annie/find_herb/����") && me->query_temp("annie/find_herb/����ѩ") && me->query_temp("annie/find_herb/Ҷ��ʿ")	)
	{
		message_vision(query("name")+"�ɵ�����Ҷ���֪�����ǡ����ǡ���\n",me);
		message_vision(query("name")+"ͻ��һ��ͷЦ�����㿴������ԣ���������÷��������\n",me);
		return 1;
	}


	if (me->query_temp("annie/find_herb/����"))
	{
		message_vision(query("name")+"ҡͷ������ίʵ���ǵ��ˡ�\n",me);
		return 1;
	}
	message_vision(query("name")+"����������̲ݣ����̲ݣ�����\n",me);
	message_vision(query("name")+"��˼���ã�̾������������ʱ������˵����ζҩ�ģ�ֻ�����ʲô�����ǵ��ˡ�\n",me);
	message_vision(query("name")+"˵��������Ҿ�Ӫҩҵ�����·��Ƴ��о������ǵ��̣����ҹ�ȥ����������\n",me);

	me->set_temp("annie/find_herb/����",1);
	return 1;
}


void create()
{
	
	set_name("����",({"wan chunliu","chunliu","wan"}));
    set("nickname",HIG"��ҽ"NOR);
	set("long", "
���˱������𽭺��ġ����ֻش�����ҽ��������˵ֻҪ���߻���һ
�����ڣ�������ҩ��������\n");

	set("age",45);
	set("attitude", "friendly");
	set("combat_exp", 5500000);
	set("skill_public",1);		
	set("inquiry", ([
        	"���̲�" : 	(: annie_drug :),
        	"�����ϲ�":	(: do_story :),
        	"����":		(: do_story :),
        	"�κ�":		(: do_cure :),
   	]));
	
	set("chat_chance", 1);
    set("chat_msg", ({
        	"������ͷ��˼�������û����ʶ����Ĵ��ڡ�\n",
     }) );
	set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
        	(: auto_smart_fight(40) :),    
    }) );
	set_skill("prescription",200);
	setup();
	auto_npc_setup("guardian",200,190,0,"/obj/weapon/","fighter_u","herb",1);
	carry_object("/obj/armor/cloth")->wear();
		
}

int recognize_apprentice(object ob)
{
        if (!REWARD_D->check_m_success(ob,"С����ҽ") && !ob->query("free_learn/prescription"))
        {
                message_vision("����ҡҡͷ�������Ĳ��ϡ�\n\n",ob);
                return 0;
        }
    	ob->set("free_learn/prescription",1);	// some ppl didn't get this mark before the learning is implemented
    	return 1;
}

int prevent_shown(object me, string skill)
{
	if ( skill == "prescription")
		return 0;
	
	return 1;
}

int prevent_learn(object me, string skill)
{
  if (skill != "prescription")
  {
      command("shake");
      command("say �Ϸ�ֻ������ˣ��ɲ�����ɱ�ˡ�");
      return 1;
  }
  return 0;
}


int do_story(){
	
	object me;
	me=this_player();
	
	if (REWARD_D->riddle_check(me,"С����ҽ")<2 
			&& !REWARD_D->check_m_success(me,"С����ҽ")) {
		command("say С�϶�ֻ���β����ˣ������ģ��ܲ��ˣ�Ҳ����ܡ�");
		return 1;
	}
	
	tell_object(me, CYN"
�������˿��㣬����Ƭ�̵���Ƽ���Ѿ��Ѻ�֩����¶����������ˣ����¶�˵��������
���������������֮��ԭ�����˹ȵ�����������ɢ��ɢ����������Ҳ�������˱��ֵ�
��������ط�������û����������

ȥ�����¼䣬ʮ����˺�Ȼ�����˺ö࣬��������ŷ���ֵܡ���ԯ���⡣�������˾�¥
���ݣ����������������˸������������˵��Ҫϴ�ĸ��棬��л�����������֮����

Ȼ������дӴ�Ҳ�������İ�����ˣ����Ǵ����ɫ�Ҵң�סһ�����Ͼ�û����Ӱ����
���Ļ���ҲĪ���������ʧ�ˡ�����ʹ��ˣ����񲻺ã���˼�ɲ�����������һ������
�á���������Ƽ�����˺�֩���ڰ��в쿴��û�뵽ȴʧ�ֱ�ŷ���ֵ���ס����������ײ
�ƣ�����������׶༪���ˡ�������

����˵������������Ƥ������Ī��������˹���Ҫ�ȷ�Ѫ�꣬���������ˡ�

����̾�����������ˣ��ﲻ����ʲôæ�����Լ���취�ɡ��Ҿ������������ţ����
���и�ͷʹ��ʹ��������Ѫ�ģ�ֻҪ�ܻ������Ҿ��뷨����"YEL"�κ�"CYN"��\n"NOR);
		
		return 1;
}


int do_cure(){
	
	object me;
	me = this_player();
	
	if (!REWARD_D->check_m_success(me,"С����ҽ")) {
		tell_object(me,CYN"������ü��չ���ȣ�������ȱ����֦һҶ�����䲻ȫҩ����\n"NOR);
		return 1;
	}
	
	if (me->query_temp("marks/eren/in_cure")){
		tell_object(me,"����˵���úþ�����Ϣ���������ʵ��ˡ�\n");
		return 1;
	}
	
	if (me->query("eff_kee")>= me->query("max_kee")
		&& me->query("eff_sen")>=me->query("max_sen")
		&& me->query("eff_gin")>= me->query("max_gin")){
		command("say �����û��ʲô�˰���");
		return 1;
	}	
		
	message_vision(CYN"�����˳�һ����ɫ��ҩ����$N������ȥ��\n"NOR, me);
	command("say ��ҩ�Է����������������ҷ��о����������мǲ����뿪������������֮�ǣ�\n\n");
	tell_object(me,YEL"�����ҩ��������һ������֮�������ྭ����ע�롣\n"NOR);
	me->set_temp("marks/eren/in_cure");
	environment()->do_recover(me, 0);
	return 1;	
}
	

int accept_object(object me, object obj){
	
	if (obj->query("name") != "��֦һҶ��"
			|| !obj->query("wanchunliu")) 
		return 0;
		
	command("smile");
	command("nod");
	command("say �ã���������֦һҶ����Ѱ�����˲���һ����"YEL"�κ�"CYN"�ˡ�");
	command("say �����ⴿ�ӣ��ҿɴ�����һЩҽ��֮���������Ծȶ��кô���");
	REWARD_D->riddle_done(me,"С����ҽ",20,1);
	me->set("free_learn/prescription",1);
	return 1;
}
		