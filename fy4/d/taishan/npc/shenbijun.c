#include <ansi.h>
inherit NPC;

int fengxian();

void create()
{
        set_name("��赾�", ({ "shen bijun","shen" }) );
        set("gender", "Ů��" );
        set("nickname", HIG"��������"NOR );
        set("long","
�����������κ���Ҳ�޷����ݵģ������û����������ˣ������������������ˣ�
���˻�˵����ͼ�����ˣ���������֧�����ܻ������ķ��ϣ����������ϵ����ӣ�Ҳ
��û��������ᡣ�����κ��ˣ�ֻҪ������һ�ۣ�����ԶҲ�޷����ǡ����������
�еĵ�һ���ˡ�����ھ���  \n"
                );
        set("attitude", "peaceful");
        set("age", 24);
        set("per", 70);

        set("combat_exp", 600000);

        set("chat_chance", 1);
        set("chat_msg", ({
             "��ھ�������Ȼ������̾�˿����������۾���\n",
        }) );

        set_skill("unarmed", 50);
        set_skill("dodge", 80);
        set_skill("parry", 80);
        set_skill("move", 80);
        set_skill("fall-steps", 50);
        set_skill("meihua-shou", 50);
        map_skill("dodge", "fall-steps");
        map_skill("unarmed", "meihua-shou");

	set("inquiry", ([
      		"ɴ��":  "Ŷ���������ڷ��Ƴ�Сסʱ�������кܶ��ſ�ǰ������ɴ��
���������ÿ���ɴ��ſ�ȷ�ϡ� \n",	
        	"׺��÷����ɴ��" : "Ŷ���������ڷ��Ƴ�Сסʱ�������кܶ��ſ�ǰ������ɴ��
���������ÿ���ɴ��ſ�ȷ�ϡ� \n",	
   		"��С��":	"���뿪���Ƴ�ʱ���Ѳ����̸�����������Ҳ��֪����ô���ˡ�\n",
   		"������":	(: fengxian :),
   		"��Ǯ��":	"��Ǯ���ǽ����������ϵĵ�һ�������Ϲٽ���ڷ��Ƴ��ｨ����̳��\n",
   		"�Ϲٽ��":	"��Ǯ���ǽ����������ϵĵ�һ�������Ϲٽ���ڷ��Ƴ��ｨ����̳��\n",
   		"̸��Ʒ��":	"action��ھ�΢Ц���\n",
   		"̸���۵�":	"���˰�����ϲ���赶Ūǹ�ġ�\n",
   		"������":	"action��赾�ҡҡͷ˵����ֻ֪�����ڽ�Ǯ���У�����ɲ������\n",
   	]));                
   	
        setup();
        carry_object("/d/fugui/npc/obj/w_skirt1")->wear();
}


int	accept_object( object who, object what) {
	if (what->query("name") == HIG"׺��÷����ɴ��"NOR) 
	{
		if (!what->query("real2") || !REWARD_D->check_m_success(who,"�һ���̽��")){
		message_vision(GRN"
��赾���ü΢�壬����������֣������ʵص�ɴ���ܾ��ú����죬����������
������أ�\n"NOR,who);
			return 0;
		}
		message_vision(WHT"
��赾������Ŷ��һ���������ŵ�����һ������ǽ���������һ���ġ����
�º������������ר�����Ҷ��Ƶģ����÷��������Ŷ����غ����ϡ�
 
��赾�ͻȻ����һ��������������������Ժ�СŮ�ӱ���û�����ʲô�ˣ�
��Ϊ��Ҳ��������ʱ���ľ��ˡ� \n"NOR,who);
		if (!REWARD_D->check_m_success(who, "��̽��Ǯ"))
			REWARD_D->riddle_set(who,"��̽��Ǯ",1);
		else
			message_vision(WHT"
��赾������ȥ�����������Ứ������������\n\n"NOR, who);

	//	who->set("maze/��������",1);
		return 1;
	}
	return 0;
}

int fengxian(){
	if (REWARD_D->check_m_success(this_player(),"�һ���̽��"))
		message_vision(GRN"
��赾�����������ʵ���Ǹ��ſͣ���������̸��Ʒ������ΪͶ������˵��Ӧ��
Ǯ������Ϲٽ��֮�������ڽ�Ǯ����������̸���۵��� \n"NOR,this_player());
	else
		message_vision(GRN"
��赾�����������ʵ���Ǹ��ſͣ���������̸��Ʒ������ΪͶ���� \n"NOR,this_player());
	return 1;
}