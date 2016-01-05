
inherit NPC;
inherit F_VENDOR;
#include <ansi.h>

int do_qrestore();
int insurance();

void create()
{
    set_name("�Ϲ�ѩ��", ({ "shangguan xuer", "snow","xuer" }) );
	set("gender", "Ů��" );
	set("age", 12);
	set("title", CYN "Ư���ĺ�"NOR);
	set("long","һ�������������ӵ�СŮ������������͵͵���֡�\n");
	set("combat_exp", 150000);
	set("attitude", "friendly");
	set("NO_KILL","��ô�ɰ���СŮ����������ô�������֣�\n");
	set("per",30);
	set("vendor_goods", ([
		"obj/item/player_bag1": 100,
		"obj/item/player_bag2": 100,
		"obj/item/player_bag3": 100,	
		"obj/item/ccard":		100,
		"obj/item/keychain":	100,
		"obj/item/gold_pawncard": 100,
		"obj/item/silver_pawncard": 100,
			
	]) );
	
	set("inquiry", ([
	       	"insurance": 	(: insurance :),
	       	"�Ʋ�����": 		(: insurance :),
	       	"�������":		(: do_qrestore :),
			"treasurebox":		(: do_qrestore :),
			"treasure box":		(: do_qrestore :),
         ]) );
		
	set_skill("unarmed",150);
	set_skill("dodge",150);
	set_skill("parry",150);
	setup();
	carry_object("/obj/armor/cloth")->wear();
}

void init(){
	add_action("do_vendor_list","list");
	::init();
}

int do_qrestore(){
	
	object me, ob, newob;
	string id,file;
	int num;
	mapping t_items = ([]);
		
	me = this_player();
	
	if (present("treasure box", me)) {
		command("giggle");
		command("say ������в����Ѿ������������ô��");
		return 1;
	}
	
	seteuid(ROOT_UID);
	
	if (!me->query("update/12_treasurebox")) {
		id = me->query("id"); 
		file = sprintf(DATA_DIR "user/%c/%s/treasurebox", id[0],id);
		ob = new("/obj/item/questbox");
		if (!ob) {
			write("�ļ���д����������֪ͨ������ʦ��\n");
			return 1;
		}
		
		ob->set("owner_id", id);
		if( file_size(file + __SAVE_EXTENSION__) >= 0 ) {
			ob->restore();
			if (mapp(t_items = ob->item_list()))
				num = sizeof(ob->item_list());
			else
				num = 0;
			
			if (num >0)  
				me->set_items(t_items);
			
			if (rm(file+ __SAVE_EXTENSION__))
				log_file( "QBOX_LOG", sprintf("(%s) %s ���������ת���ɹ���%d����\n", 
				ctime(time()),
				me->query("id"),
				num)
				); 
			else {
				log_file( "QBOX_LOG", sprintf("(%s) %s ɾ��ԭ�ļ�ʧ�ܡ�\n", 
				ctime(time()),
				me->query("id")));
				write("�ļ���д����������֪ͨ������ʦ��\n");
			}
		} 
		destruct(ob);
		me->set("update/12_treasurebox",1);		
	}
		
	ob = new("/obj/item/newquestbox");			
	if (ob->move(me)) {
		message_vision("�Ϲ�ѩ��Ц�����شӺ�������һ��С���ӵݸ�$N��\n", me);
		return 1;
	}
	tell_object(me,"�Ϲ�ѩ��˵����ѽ�������϶���̫�ࣨ�أ��ˣ�û������ѽ��\n");
	destruct(ob);
	return 1;		
}


int insurance(){
	object me = this_player();
	int duration;
	
	duration = me->query("timer/insurance")+ 259200 - time();
	if (duration >0) {
		tell_object(me, CYN"�Ϲ�ѩ��˵���͹����ı��ջ���"+ (duration/3600)+"Сʱ"
		 + (duration%3600)/60 + "�������ҲŹ����ء�\n"NOR); 
		return 1;
	}
			
	message_vision(YEL"$N���˵�ͷ���ӹ�̨���ó������ι�״�ı��ƾ�Ҫ�������ŵĶ����ɿ�ذ�
�˼��£��Ƕ�����������������˸�˼��£�����ཱུؽ��˼�����\n\n"NOR, this_object());

	if (me->query("deposit")< 50000) {
		tell_object(me,name()+"ҡ��ҡͷ˵���͹���Ǯׯ�Ĵ��������������������\n");
		return 1;
	}
	me->add("deposit",-50000);
	command("ya");
	tell_object(me,CYN"�Ϲ�ѩ��˵�����ˣ��͹����Ͱ��ĳ��Űɣ�����������Ч��\n"NOR);
	me->set("timer/insurance",time());
	return 1;		
}


void reset()
{
	set("vendor_goods", ([
		"obj/item/player_bag1": 100,
		"obj/item/player_bag2": 100,
		"obj/item/player_bag3": 100,	
		"obj/item/ccard":		100,	
		"obj/item/keychain":	100,
		"obj/item/gold_pawncard": 100,
		"obj/item/silver_pawncard": 100,
	]) );
}
		
