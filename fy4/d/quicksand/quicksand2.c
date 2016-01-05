// Room: /d/chuenyu/trap_castle.c
#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "��ɳ");
	set("long", @LONG
���Ѿ�������ɳ֮�У�����û��һ�������ĵط�����һ����������ȥ������
������(pull)��һ�ѣ�������뿪������±ȵ��컹�ѡ����ƺ��Ѿ������ڰ��޳�
���������֡�
LONG
	);

        set("NONPC",1);

	set("coor/x",-1080);
	set("coor/y",-10);
	set("coor/z",-10);
	setup();
}

void init()
{	object ob;
	if( interactive( ob = this_player()))
	{
	remove_call_out("sinking");
	call_out("sinking", 1, ob);
	}
}

int sinking(object ob)

{
	int i;
	int damage;
        if( ob && environment(ob) == this_object())
	{
	message_vision(HIW"$N������ɳ��������һЩ����", ob);
	message_vision("$N�����ھ����п��˳�������\n"NOR, ob);
	damage = random(5)+1;
	i =  (int)ob->query("kee");
	ob->set("kee",(int) i - damage);
	if( environment(ob) == this_object())
	call_out("sinking",random(5)+5, ob);	
	}
	else

	return 1;
}

void reset(){
	object *inv;
	int num,i;	
	::reset();
	inv = all_inventory();
	for (i=0;i<sizeof(inv);i++){
		if (userp(inv[i])) {
			message_vision(HIW"��Ѱ���þ�ȫ����������$N����ɳ�о��˳�����\n"NOR, inv[i]);
			sscanf(file_name(this_object()),__DIR__"quiclsamd%d",num);
        	inv[i]->move(__DIR__"desert"+num);
        	tell_object(inv[i],CYN"\n��Ѱ����������Դ����Ժ�С������˵�ձ���ʧ�ˣ�\n\n"NOR);
		}
	}
}	