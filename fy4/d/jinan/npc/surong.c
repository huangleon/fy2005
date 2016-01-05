#include <ansi.h>
inherit NPC;
void make_makeup(object me);
int ask_for();
void create()
{
 	set_name("������", ({ "su rongrong","su" }) );
 	set("title", "����֪��");
 	set("gender", "Ů��" );
 	set("age", 21);
 	set("per", 100);
 	set("long",
"���ż���������ĳ�ȹ������б��ӳ�������ɵķ��٣��峺�ĺ�ˮҲӳ��
���������Ц�ݣ��������������ϵ����ӣ����Ѳ�ʳ�˼��̻𡣾�˵������
�Ĵ����ǵ��꾪�ž��޵�С��ͯ����������������ߣ�����룩�Ĺ���
Ҳ�������������\n");
 	set("combat_exp", 80000);
 	set("chat_chance", 1);
 	set("chat_msg", ({
		"���������ֲ��˸�������ĵ�����֪�������������֮����ô���ˣ�����ת
���ˣ���ý������Щ�·���\n",
		"��������ȻЦ������˧ҹ���㣬���겻֪�ںη����ֵ������Ĵ������ˡ�����\n",
        }) );
 	
 	set("attitude", "friendly");
  	set("inquiry", ([
        	"mask" : (: ask_for :),
        	"���" : (: ask_for :),

        ]));
 	setup();
    	carry_object(__DIR__"obj/changbao")->wear();
    	carry_object(__DIR__"obj/lotuspetal");
}


void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_answer","answer");
}

void greeting(object me)
{
	object basket,food;
	
	if(!me->query("makeup_buyer")) return ;
	if(me->query("makeup_buyer")+60>time())
	{
		message_vision(CYN"�����ذ�����һ�ۣ�˵�������𼱣���Ҫ�ٵ�һ�ᡣ��\n"NOR,me);
		remove_call_out("make_makeup");
		call_out("make_makeup",60+me->query("makeup_buyer")-time(),me);
		return ;
	}
    message_vision(CYN "�����ذ�����һ�ۣ�˵�������ǵģ�������ȥ�ˣ�������\n"NOR,me);
	make_makeup(me);
	return ;
}



int ask_for()
{
	object me;
	
	me=this_player();	
	if(me->query("mark/su_makeup"))
	if(me->query("mark/su_makeup")+600<time()) 
	{
		message_vision("�����ض���һЦ����������˼��������̫���ˣ����������ɡ���\n",me);
		return 1;
	}
	if(me->query_temp("search_su_makeup"))
	{
        message_vision(CYN "������ݸ��һЦ��ʵ��û���ӣ�ȱ��һ����û��������õ���ߡ����� \n"NOR,me);
		return 1;
	}

      message_vision(CYN "��������Ŀ��ת�������������������˵ֻ��ƤëС�����ѵǴ��ţ������� 
ʵҲ�ܻ�������������ҵ���"YEL"С¹�ġ���ë�����˻��߹�����ȥ�ġ���Ƥ���� 
��С�񵰡��ĵ��塢һ�����廨�롹��������������˿�����һ��꡹�Ļ��ۣ�
����Ҫһ֧���Ǻ��ʡ�������"CYN"�һ���������Կ��� \n"NOR, me);

	me->set_temp("search_su_makeup",1);
	return 1;
}

string *material_names=({
    "��ë","�˻���Ƥ","С��","�廨��","�һ���",WHT"�Ǻ���"NOR,"������"
	});

int accept_object(object me, object ob)
{
	string ob_name;
	int i,success,makeup_ok;
	
	if(!me->query_temp("search_su_makeup")) 
		return 0;
		
	ob_name=ob->query("name");
	success=1;
	makeup_ok=0;
	for(i=0;i<7;i++)
	{
		if(ob_name==material_names[i])
		{
			if(me->query_temp("su/"+ob_name))
			{
				message_vision("��������ȻһЦ��˵��������������Ѿ������ء���\n",me);
				return 0;
			}
			me->set_temp("su/"+ob_name,1);
			message_vision("��������ȻһЦ��˵��������л��λ"+RANK_D->query_respect(me)+"Ϊ������"+ob_name+"����\n",me);
			makeup_ok=1;
		}
		success=success*me->query_temp("su/"+material_names[i]);
	}
	if(!success) return makeup_ok; 
	tell_object(me,"��������Ҫ��˭������أ�(answer id)\n");
	set("answer_person",me);
	me->delete_temp("search_su_makeup");
	return 1;
}

int do_answer(string arg)
{
	object me,target;
	
	me=this_player();
	if(me!=query("answer_person")) return 0;
	target=find_living(arg);
	if(!target || (target && target->query("wiz_invis")))
	{
		tell_object(me,"��˵������˲�����ѽ������\n");
		return 1;
	}
	me->set("make_makeup_for/id",target->query("id"));
	me->set("make_makeup_for/name",target->query("name"));
	me->set("make_makeup_for/short",target->short());
	me->set("make_makeup_for/long",target->long());
	message_vision(GRN "����������ص��ͷ������������������һ��"+target->query("name")+"����߿��������� \n"NOR,me);
    	message_vision(YEL"�����ؾ۾�����С������ؿ�ʼ���������������  \n"NOR,me);
    	me->set("makeup_buyer",time());
	call_out("make_makeup",6,me);
	return 1;
}


void make_makeup(object me)
{
	object makeup,pozhi;
	
	if(!present(me,environment()))
		return ;		


	makeup=new(__DIR__"obj/skinmask");
	makeup->set("armor_prop/id", ({capitalize(me->query("make_makeup_for/id"))}) );
	makeup->set("armor_prop/name", ({me->query("make_makeup_for/name")}) );
	makeup->set("armor_prop/short", ({me->query("make_makeup_for/short")}) );
	makeup->set("armor_prop/long",({me->query("make_makeup_for/long")}) );

	
    message_vision( CYN "һյ�蹦�������ز��˲���ͷ���㺹��΢Ц���������ˣ��Һ�������û 
��ô������ 

  �����ظ�$Nһ�����µ���ߡ�  \n"NOR,me);
	me->delete_temp("su");
	me->delete("makeup_buyer");
	me->set("mark/su_makeup",time());
	makeup->move(me);

/*  message_vision( CYN "һյ�蹦�������ز��˲���ͷ���㺹���������������˵���ߣ�\n��ü������˵���Դ��Ǵ�ЦЦ�������ҹ���֮���Ҿ���û���ɹ���ߣ�����\n"NOR,me);
    ccommand("say �㻹��ȥ�ҳ���ķ����ɡ�"); 
    pozhi = new("/d/fy/npc/obj/pozhi");
    pozhi->set("value",1);
    pozhi->move(this_object());
    ccommand("give pozhi to "+me->get_id());*/
    
    me->delete_temp("su");
    me->delete("makeup_buyer");
    me->set("mark/su_makeup",time());
	return ;
}
		
