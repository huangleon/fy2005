
inherit NPC;
#include <ansi.h>
void create()
{
        set_name("��ɤ��", ({ "music bird","bird" }) );
        set("race", "����");
        set("age", 5);
        set("long", "��ɤ�̵������ö��������ḻ��䣬��ʱ���������Ļ��߰˸����ڣ�
��質���١� \n");
        set("max_kee", 5);
        set("spi", 100);
    	set("chat_chance", 1);
    	set("chat_msg", ({
        "��ɤ�̳����������������������Ȼ�Ŵ˶����顣\n",
        "��ɤ�̳�����������峣���࣬�ں�����Ӧ�ųɡ�\n",
        "��ɤ�̳�������������ɮ�ζϣ���ǰʱ�������塣\n",
        "��ɤ�̳��������ֵ��������棬������԰��������\n", 
            }) );       	

        set_skill("dodge", 150);

        setup();
}


int kill_ob(object me)
{
	message_vision("$N���������һ�ߣ�һչ��򣬺��ķ����ˡ� \n",this_object());
	destruct(this_object());

	return 1;
}


string *event1_msg=	({
	"��ɤ�̾������������������˼��£�û�����ѡ� 
��ƫ��ͷ�����ž��ֵ���������һ����� \n",
	"��ɤ�̺�Ȼ˵����������������һλ��Ů�� 
���Ҳ���һֻһ��������������������ľ��顣�� \n",

	"�����û���������ö��������������������ɤ��һʱ�е㷢���� \n",

	"��ɤ�̽���˵������Ϊ��������������������ҿ��Ը������� 
������Զ���õ��Ҹ棬ֻ�����ܷ����ҡ��� \n",

	"������һ��������ɤ�̵��˵�ͷ�� \n",

	"��ɤ��˵������һ���Ҹ��ǣ��������Ϊ�����ܵ��£�������ô˵ 
��Ҳ��Ҫ���š��� \n",

	"������˵�����ڶ����Ҹ��ǣ�����ʲô�£��������Ժ󶼲�Ҫ��ڡ��� \n",

	"�������Ժ󣬾����������С���ɤ�������������ƺ��������� 
���ߡ�����������ľ��������ɳ�̾һ�����ɿ����֡� \n",
	});


void event1(object me, int count)
{
	tell_object(me,event1_msg[count]+"\n");
	if(++count==sizeof(event1_msg))
	{
		this_object()->move(environment(me));
		this_object()->set("escaping",1);
		call_out("event2",1,me);
	}
	else call_out("event1",1,me,count);
	return ;
}
	
void event2(object me)
{
	
	message_vision("��ɤ��һչ��򣬷��ϸߴ�����֦����ͷ���˿�$N������һ�� 
����Ц�����������Ǵ����ǧ���ѷ�ĺû��ᡣ����ô������ 
����Ϊ�����ﺬ��һ��������䣬�����������ǻۣ���ƭ���� 
�ġ����ϧ��˱����ʧ֮���ۡ��� \n\n",me);
	message_vision("��ɤ�̿�����Ц������ \n",me);
	me->set_temp("mbescape",1);
	return ;
}


string *event3_msg= ({
	"��ɤ�̺�Ȼ�����Ϸ�����������ͣ��$N���ֿɼ��ĵط�����$N��һ��ָͷҲ�첻���ˡ� \n",
	"��ɤ���Ŷ�$N˵�����Ҹ�����Ҹ濴����û���á��� 
���Ҹ����㣬�������Ϊ�����ܵ��£�������ô˵��Ҳ��Ҫ���š� 
����ôС�����ﺬ������������𣿿����ƫƫ���ˡ��� \n",

	"���Ҹ����㣬����ʲô�£��������Ժ󶼲�Ҫ��ڡ������ֺ�� 
�����ң�Ϊ��ץ��ˤ��������ӡ��� \n",

   	"��ɤ��̾�˿����������İ������İ�...�� \n",
    
   	"��ɤ�̷���Զ��������̾�����ƺ���Զ��������ߡ� \n",
  });

void event3(object me, int count)
{
	message_vision(event3_msg[count]+"\n",me);
	if(++count==sizeof(event3_msg))
		destruct(this_object());
	else call_out("event3",1,me,count);
	return ;
}


int imbue_event(object me, object room){
	object weapon, ob, *inv, obj;
	string prop;
	int i;
	mapping data;
	
	if(!interactive(me) || environment(me) != room) {
		return 0;
	}

	obj = me->query_temp("weapon");
	if(objectp(obj) && obj->query("owner")) {
		weapon = me->query_temp("weapon");
	} else { 
		inv = all_inventory(me);	
		for(i=0; i<sizeof(inv); i++) {
			if(inv[i]->query("weapon_prop") && inv[i]->query("owner")) {
				weapon = inv[i];
				break;
			}
		}	
	}
	if(!objectp(weapon)){
		if(!objectp(obj)) {
			message_vision(HIB"\n������ɤ�̵�Զ�ɣ��ö���Ц���ƺ�һ˿˿�ڿ����л�����\n"NOR, me);
		} else {
			message_vision(HIB"\n������ɤ�̵�Զ�ɣ��ö���Ц���ƺ�һ˿˿�ڿ����л�����\n"NOR, me);
		}
	}else{
		message_vision(HIB"\n������ɤ�̵�Զ�ɣ��ö���Ц���ƺ�һ˿˿�ڿ����л�����\n"NOR, me);
		message_vision(HIB"$N���е�" + weapon->name() + HIB"�������ö���Ц������������Խ������֮����\n"NOR, me);
		message_vision(HIB"����Ц���ĵ�ȥ���������ཥ����ȥ��\n"NOR, me);
	}
	
	data = ([
		"name":		"��ɤ��֮��",
		"target":	me,
		"att_1":	"int",
		"att_1c":	1,
		"mark":		1,
	]);
	REWARD_D->imbue_att(data);	
	
}

void event4(object me){
	
	if(!me ||!living(me)){
		return ;
	}
	this_object()->move(environment(me));
	message_vision(HIG"��ɤ�̺�Ȼ�����Ϸ�����������$Nͷ���������衣 
��ɤ��Ц�Ŷ�$N˵����������һ�����²��ڵ��ˡ��� 
��ɤ�̽�Ц�������������ȷ��������ڲ�ľ��ʢ�ĵط�����Ե�Ļ���ͻ��ҵ������� 
��ɤ�̷���Զ����\n"NOR,me);
	me->start_busy(3);
	tell_object(me, "\n����ǰ�����������ƺ�������ʲô����ľ�ɫ��
"BGRN+HIG"
    �����ݵصı�Ե����һ��֦Ҷ��ï��С���������Ǳ��̵Ĳݵأ�һ��ƽ���Ĵ�
ʯͷѹ�ڲݵ��ϣ������ɫ��С������ʯͷ���Աߡ�����ʱһ�����С���紵����
������ȫ������һ�������ĺõط���"NOR" 
	
������ɢ��һ���ƺ��ǳ��ξ���\n");
	
	if(!REWARD_D->imbue_check(me,"��ɤ��֮��")){
		imbue_event(me, environment(me));
	
		if (!REWARD_D->check_m_success(me,"��ɤ��֮��"))
		{
			REWARD_D->riddle_done(me,"��ɤ��֮��",100,1);
		}	
	} 
	
	destruct(this_object());

}