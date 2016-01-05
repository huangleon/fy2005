#include <ansi.h>
inherit NPC;
int send_fan();

void create()
{
        set_name("�ϸ���", ({ "old woman", "woman" }) );
        set("gender", "Ů��");
        set("age", 49);
        set("long",	"�ϸ�������æ��������\n");
        set("attitude", "peaceful");
        set("combat_exp",2000);
        set("inquiry", ([
				"help" : (: send_fan :),
				"��æ" : (: send_fan :),
				"��" : 	(: send_fan :),
                "�ͷ�":	(: send_fan :),
                "����" : (: send_fan :),
				"�ϰ�" : "������ׯ�ڵ���ɻ���������˳ԡ�",
				"rice":	(: send_fan :),
        ]) );
        set("count",0);
        setup();
    	carry_object("/obj/armor/cloth")->wear();
		carry_object(__DIR__"obj/basket2");
}

int send_fan()
{
        object ppl, bag, me, rice, vege, chop;
		string lastname;
		int count;
		
		me = this_player();
		
		ppl = query("lastone");
		if (objectp(ppl))
			lastname = ppl->name(1);
		else 
			lastname = "����";
		
		if (me==ppl) {
			command("say �Ҳ��Ǹս����ͷ�ô���͵�����");
			return 1;
		}	
		
		if (query("count")>=3) {
			command("say ��л��λ"+ RANK_D->query_respect(me) + "��������"+lastname+"�Ѿ������͹����ˡ�\n");
			return 1;
		}
		
		message_vision("�ϸ��˸��˵�ָָ���ϵķ���˵������λ" + RANK_D->query_respect(me) +"���������"YEL"�ϰ�"NOR"��ȥ����\n",me);
		bag = new(__DIR__"obj/basket2");
		rice = new(__DIR__"obj/rice");
		vege = new(__DIR__"obj/vege");
		chop = new(__DIR__"obj/chopstick");
		rice->move(bag);
		vege->move(bag);
		chop->move(bag);
		bag->move(environment());
		set("lastone",me);
		count = query("count");
		count++;
		set("count",count);
		return 1;
}

void reset(){
	delete("lastone");
	delete("count");
}
