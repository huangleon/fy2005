// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "��Ժ��");
        set("long", @LONG
�����沢���ߴ��ǽ���ŵô���֮��������ֺ�Ժ��Ҳ����������ѧ�ķ�Դ��
--������Ժ��ǽǰվ�ż���������ɮ���ֳֽ䵶����˿������ע����ǰ����
LONG
        );
        set("exits", ([ 
  		"north" : __DIR__"neiyuan",
  		"southup" : __DIR__"qianfe",
	]));
        set("objects", ([
                __DIR__"npc/monk81" : 1,
                __DIR__"npc/monk82" : 1,
       	]) );
        set("outdoors", "shaolin");
	set("coor/x",0);
	set("coor/y",30);
	set("coor/z",10);
	setup();
}

int valid_leave(object me, string dir)
{
        object *env, ob;
	int i;
		
	env = all_inventory();
	for (i=0; i<sizeof(env);i++)
	{
		if (env[i]->query("npc_team") == "shaolin_blade")
		{
			ob = env[i];
			break;
		}
	}

	if (F_LEVEL->get_level(me->query("combat_exp"))>=65){
		if (objectp(ob) && me->query("vendetta/shaolin")>=1)
			ob->ccommand("say ʦ����Ը��ˣ��������ӷŽ�ȥ���Ŵ򹷡�");
		return ::valid_leave(me,dir);
	}
	        
	if( userp(me) &&
		dir=="north" && ob
		&& me->query("vendetta/shaolin")>=1 )
		return notify_fail( ob->name()+ "�ȵ��������ӣ��Ҵ�������Ժ��\n");
        
	if( userp(me) &&
		dir=="north" && ob &&
		(me->query("family/generation") > 22  ||
		me->query("family/family_name") != "������"))
		return notify_fail(ob->name()+"˵����ֻ�����������ҵ��Ӳſ��Խ���������Ժ��\n");
	return 1;
}
