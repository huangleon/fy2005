inherit SMART_NPC;
#include <ansi.h>

int leave();
int annie_new_by();

void create()
{
    set_name("����" , ({ "hua yin","hua" }) );
    set("nickname",HIR"������"NOR);
    set("long", "����Ů��ɫ��ȹ������ƮƮ���������ɣ��������������˫�������ػ�����\n�������衣\n");
    set("attitude", "friendly");
    set("per",60);
    set("age", 29);
    set("gender", "Ů��" );
    create_family("���Ƴ�",1, "��Ů");
    set("combat_exp", 2200000);
    set("chat_chance", 2);
    set("chat_msg", ({
	"������Ű�����˫�㣬������б���ڻ����У����ɵĴ��۾�͵͵�ش������㡣\n",
	"����ճ�����������ձ��ǽ���ʦ�ֵ���������"YEL"��"NOR"��ʲô�͸�����ʦ���أ�\n",
      }) );
    set("inquiry",  ([
	"��": (: annie_new_by :),
	"painting": (: annie_new_by :),	
	"���ν���" :  (: leave :),
      ]) );
    
    set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
	(: auto_smart_fight(20) :),
      }) ); 		
    
    auto_npc_setup("wang",150,120,0,"/obj/weapon/","fighter_w","qingfeng-sword",1);
    set_skill("spring-water",50);
    set_skill("iron-cloth",50);
    setup();
    carry_object("/obj/armor/cloth")->wear();
    carry_object("/obj/weapon/sword")->wield();
}

int annie_new_by()
{
    object me = this_player();
    
    if (me->query("combat_exp")<3100000) {
	tell_object( me, CYN"����̾������ѽ�����׻�ʲô���أ��ܲ��ɻ�����ô���������ļһ�ɣ�\n"NOR);
	ccommand("sigh");
	tell_object( me, CYN"�����Ĳ����ɵĿ����㣬˵���������������һ�ң�������Ҳ��������ǿǿ���������������˰ɣ�\n"NOR);
	tell_object( me, WHT"����ȼ������ߣ�70����С���ﲻ�����㡣\n"NOR);
	// snicker
	return 1;
    }	
    
    if (REWARD_D->riddle_check(me,"��ͼһ��") != 1 )
    {
	tell_object( me, CYN"����̾������ѽ�����׻�ʲô���أ��ܲ��ɻ�����ô���������ļһ�ɣ�\n"NOR);
	tell_object( me, CYN"��������ϸ�����������ƣ�˵����\n"NOR);
	tell_object( me, CYN"�����������ⲻ��������ӣ�Ҳ��������Ļ�������Ϊ�ء�\n"NOR);
	tell_object( me, "\n");
	tell_object( me, CYN"����ָ��ָ���ߣ��ֵ�����˵���Ƴǵ�С��̯�ϰ�����λ���ӵĸ��֣�\n"NOR);
	tell_object( me, CYN"����������ƽ��������ģ����ն�����̫�ͣ������Ϻܶ�󱲣�\n���Գ�����Ϊ�������յļ��飬��Ȼ�������������ԶԶ���ڳ�����ġ�\n"NOR);
	ccommand("say ��Ҫ��ҪҲȥ���ԣ�");
	ccommand("say �������գ��������ｭ����Ҳ������СŮ�ӣ���Ͼʱ�̣������Ƶ���䡣");
	ccommand("say СŮ�Ӷ���������������Ƶ���ɽɽˮˮ������ȥ���������õ��Ǿ������ꡣ");
	ccommand("wink");
	ccommand("say ���ڣ���Ҫ�������ʦ�ֻ�ʲô�ˣ����Լ��Ĵ�תת�ɣ�С�ı������ʦ����");
	// tell_object( me, "�ϣϣУӣ���ʲô�¶�û�ɡ�\n");
	// snicker
	return 1;
    }
    ccommand("emote ����Ц��������ʦ�ֵ�����������Ҫ��һ����õ��Ի����͸�����
�����ͷ�죬�ѵ���Ҫ������ʾ���ܡ���������

�����������һ�������ʮָ�૵�������Ҫ������������轣ͼ�����������������С�
�庣�ֵ�����ʣ������������ӵĲ��¼㣬������������ۣ�����⡣���ܰ��ҽ���һ��ô��");
	REWARD_D->riddle_set(me,"��ͼһ��",2);
	return 1;
}

string *material_names=({
    "�����","���¼�","�������������","�����"
        });

int accept_object(object me, object ob)
{
        string ob_name;
        int i,success,makeup_ok;
        
        ob_name=ob->query("name");
        success=1;
        makeup_ok=0;

		if (REWARD_D->riddle_check(me,"��ͼһ��") != 2 
			&& REWARD_D->riddle_check(me,"��ͼһ��") != 3)
		{
			ccommand("emote ��Ц������л���������ﵱ�ɽ��ҳ�ҹ��į��");
			return 1;
		}
		if (REWARD_D->riddle_check(me,"��ͼһ��") == 3 && me->query_temp("annie_by_1_2_4"))
		{
			ccommand("emote �ɻ�����㻹�����Ұѻ���ȥô��");
			return 0;
		}

        for(i=0;i<4;i++)
        {
                if(ob_name==material_names[i])
                {
                        if(me->query_temp("annie/by_hy/"+ob_name))
                        {
                                message_vision("������ȻһЦ��˵��������������Ѿ������ء���\n",me);
                                return 0;
                        }
                        me->set_temp("annie/by_hy/"+ob_name,1);
                        message_vision("������ȻһЦ��˵��������л��λ"+RANK_D->query_respect(me)+"Ϊ������"+ob_name+"����\n",me);
                        makeup_ok=1;
                }
                success=success*me->query_temp("annie/by_hy/"+material_names[i]);
        }
        if(!success) return makeup_ok; 
        message_vision("����΢΢һЦ�������л���̿����¼�ֽ����ī��ʣ��������Ƶ�������������\n",me);
        me->delete_temp("annie/by_hy");
        message_vision("Ƭ��֮�ᣬ���������ī����$N����Ц�������������͸���ʦ�ֽ�������ô��\n",me);
        ob = new(__DIR__"obj/painting");
        ob->move(me);
		me->set_temp("annie_by_1_2_4",1);
        message_vision("����ݸ�$Nһ�����轣ͼ��\n",me);
		REWARD_D->riddle_set(me,"��ͼһ��",3);
        return 1;
}


int leave()
{
    
    object room = load_object("/d/baiyun/dragonplace");
	int i = REWARD_D->riddle_check(this_player(),"��ͼһ��");
	if ( i !=4 && i != 5 && i != 6)
		return 0;
	if (is_fighting())
	{
		tell_object(this_player(),name()+"��æ���˲���������\n");
		return 1;
	}	
			
	if (environment() == room)
		return 0;
 	delete("chat_msg");
    message_vision(WHT"$N��Ѷ���ݲұ䣬������ʰ���б�ī������һ�ԣ��ҴҸ�����̨��\n"NOR, this_object());
    move(room);
    return 1;
}

void init()
{       
        object ob;
        ::init();
        if ( interactive(ob = this_player()) && !is_fighting() ) 
           {
             remove_call_out("greeting");
             call_out("greeting", 1, ob);
           }
}

void greeting(object ob)
{
        object corpse;
        if( !ob || environment(ob) != environment() ) return;

		if (REWARD_D->riddle_check(ob,"��ͼһ��") ==6 )
        {
                if (present("song shi",environment()) && present("jian dan",environment()) && present("qin xin",environment()) )
                {
                        present("jian dan",environment())->die();
                        corpse=present("corpse",environment());
                        if (corpse)
                                destruct(corpse);
                        message_vision(YEL"
�����ƺ�����û������ĵ��������ڽ������ϣ�أ�Է���ʹ�ޡ�

��ʵ���˿��㣬˫��Ѫ�죬����������ʦ��ȥ�ˡ�

�������ſ��Ž�����ʬ�����˰��죬�૵���ɵ�ϣ��ѵ�������Ϊ��ʲô����֪��ô��
ֻ�ǣ���ֻ���ң��������峺������̨Ȫˮ���۾������ڵ�����һ����ˮ��

�����������̶�У�����һȦ������ɢ��������ȥ��
��������ؿ���$Nһ�ۣ�΢΢һ������л�������˺�������֮ʱ������棬�����������ǡ�"WHT"

���˱��Ž�����ʬ����ʧ�������Ƶİ���֮�С�\n"NOR,ob);
                        ob->set("free_learn/by_magic",1);
                        destruct(present("song shi",environment()));
                        destruct(present("qin xin",environment()));
                        move(load_object("/obj/void"));
						REWARD_D->riddle_set(ob,"��ͼһ��",7);
						REWARD_D->riddle_done(ob,"��������",20,1);
						tell_object(ob,YEL"���Ȼ����ȥ��һ��Ҷ�³ǣ�������������������������˶��ơ�\n"NOR);
						die();
                }
                return;
        }

        if (present("song shi",environment()) && present("jian dan",environment()) && present("qin xin",environment()) && REWARD_D->riddle_check(ob,"��ͼһ��") ==4)
        {
                message_vision(YEL"������ʧɫ�����ڽ�������أ�Գ�����
��ʵ���žƺ�«��ȡ��������˽�ȥ�����κ���ɫ��䡣
���İ�����ý������������ǵ����������������ޣ�ʱ��ʱ����
��������Ҫȥ��ҽ��Ҷ��ʿ������\n",ob);
                message_vision("
����������߼��ˣ�����$N����ü�������������˻��������տ�������
���ɷ���ȥ��������¥����Ҷ����ǰ����\n"NOR,ob);
				REWARD_D->riddle_set(ob,"��ͼһ��",5);
        }
			

        return;
}

/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/

