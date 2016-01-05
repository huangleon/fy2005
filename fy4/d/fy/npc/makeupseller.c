// 2009 FengYun
// Edit by hippo 2009.11
// Т�� ����

inherit NPC;
inherit F_VENDOR;
#include <ansi.h>
void create()
{
	set_name("����", ({ "fang er","fang" }) );
	set("gender", "Ů��" );
	set("age", 29);
	set("title", HIY "ǧ"+ HIR "��" + HIM "��" + HIC"��"NOR);
	set("long",	"
��λ�����ɧ���ϰ�������������۶����������εεģ�ȴ����ʮ��ǰ
����������ǧ��������������Ů�����Ҵ������ݻ�װ֮��������˫��\n");
	set("combat_exp", 50000);
	set("attitude", "friendly");
	set("per",30);
	set("vendor_goods", ([
                __DIR__"obj/yanzhi":10,
                __DIR__"obj/bao":10,
                __DIR__"obj/huabag":10,
                __DIR__"obj/earth": 10,
		__DIR__"obj/pozhi":10,
		//__DIR__"obj/ikebana_stone": 0,
	]) );
	set_skill("unarmed",200);
	set_skill("dodge",200);
	setup();
	carry_object(__DIR__"obj/wch_skirt")->wear();
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(5) ) {
		case 0:
message_vision("$NЦ��˵�������ʲô���У���Щ��ȥ����������˰ɡ�\n",this_object(),ob);
			break;
		case 1:
message_vision("$NЦ�����˵������λ"+RANK_D->query_respect(ob)+
"Ҫ��ʲô��\n",this_object(),ob);
			break;
		case 2:
message_vision("$N��һ���������������$n��\n",this_object(),ob);
	}
}

int accept_object(object who, object ob)
{
	string tmpname;
	string err;
	object newmask;
	object rope,*obj;
	int i;
	string gender, name, id;
	string newfile;
	object *inv, new_skull;
	
	if(ob->query("name")=="ͷ­��" && ob->query("id")=="skull"
		&& !ob->query("recovered")){
 		if (REWARD_D->riddle_check(who,"�ž�����")!=2)
 		{
 			message_vision(CYN"
�������һ�������û��ͷ�ǹǸ�ˤ�ˡ�
����˵���Թ�¡�ض�������ѱ�������������\n"NOR, who);	
 			return 0;
 		}
		message_vision(CYN"
�����ŵ�һ��������ԥԥ���ù�ͷ�ǹǿ��˿���
����̾�˿���˵����Ȼ��֪�����˵Ĳ��£��Ҳ���Ҳ���С�

����ҧ��ҧ�촽��������Ҫ����ͷ�ǻ�ԭ����Ҫ�����ճ������ճ��Ψ��ÿ��
�������������˲Ż��͵�����Ȼ�������������Ҳ���ܰװ׾�ȡ�ˡ�\n"NOR, who);
		who->set("marks/give_skull",1); // extra steps... sorry can't fit in reward_d
		return 1;
 	}
 	
 	if (ob->query("name")==YEL"����ճ��"NOR && ob->query("skull_make")) 
 	{
 		if (!who->query("marks/give_skull"))
 		{
 			command("say С����Ų��˻����͹ٻ����������");
 			return 0;
 		}
 		who->delete("marks/give_skull");
 		message_vision(YEL"
��������$N���齩Ӳ��Ц��Ц��һ������ؽӹ�ճ��ת��󷿣�
Ƭ�̺�������ĵ�����$Nһ��������\n"NOR, who);
		new_skull=new(AREA_TAOYUAN"obj/head_e");
		if (!new_skull->move(who))
			new_skull->move(environment());
		return 1;
	}
 			
 	
	tmpname = "/open/tempmask"+sprintf("%d",time());
	message_vision("$N����$n���齩Ӳ��Ц��Ц������\n",this_object(),who);
	gender = (string)ob->query("targetgender");
	name = (string)ob->query("targetname");
	id = (string)ob->query("targetid");
	if( !stringp(id) ) return 0;
	if( !find_living(id)) return 0;
	if( !stringp(gender)) return 0;
	if( !stringp(name) ) return 0;
	if ((string)gender != "����" && (string)gender != "Ů��")
		return 0;
	id = capitalize(id);
	newfile = read_file("/obj/item/orig_mask.o");
	if( !newfile) return 0;
	seteuid(ROOT_UID);
	newfile = replace_string( newfile, "����", gender);
	newfile = replace_string( newfile, "maskman", id);
	newfile = replace_string( newfile, "������", name);
	if( !newfile) return 0;
	tmpname = tmpname + who->query("id") + ".c";

#ifdef	ENCRYPTED_WRITE	
	if( !write_file2(tmpname, newfile, 1))
		return 0;
#endif

#ifdef  NONENCRYPTED_WRITE	
	if( !write_file(tmpname, newfile, 1))
		return 0;
#endif

	newmask = new(tmpname);
	if (! rm( tmpname))
		{
		destruct(newmask);
		return 0;
		}
	if( !newmask) return 0;
	newmask->move(who);
	message_vision("$N���ĵ�����$nһ��������\n",this_object(), who);
        seteuid(getuid());
		return 1;
}

void reset()
{
	if (random(5)) {
		set("vendor_goods", ([
                __DIR__"obj/yanzhi":10,
                __DIR__"obj/bao":10,
                __DIR__"obj/huabag":10,
				__DIR__"obj/pozhi":10,
				__DIR__"obj/earth": 10,
				//__DIR__"obj/ikebana_stone": 0,
		]) );
	} else {
		set("vendor_goods", ([
                __DIR__"obj/yanzhi":10,
                __DIR__"obj/bao":10,
                __DIR__"obj/huabag":10,
				__DIR__"obj/pozhi":10,
				__DIR__"obj/earth": 10,
				__DIR__"obj/ikebana_stone": 1,
		]) );
		}
}
	

