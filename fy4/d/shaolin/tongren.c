
// annie 07.2003
// dancing_faery@hotmail.com

inherit ROOM;
void create()
{
        set("short", "ͭ�˿�");
        set("long", @LONG
����վ��һ�����У����ܵ�����������̬�����ͭ�ˣ������������Ӱ˵Ķ���
��������жϵ�ͭ��֫�壬���Ȼ���������ֲ��δ�ʦ������ɽЭ����ͭ���
δ�ɰܷ��Ľ�����˵������
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"gaoroom",
  "west" : __DIR__"kuoran",
]));
        set("outdoors", "shaolin");
	set("no_fly",1);
	set("coor/x",20);
	set("coor/y",-10);
	set("coor/z",-10);
	setup();
}

void init()
{
	delete("exits");
	if(userp(this_player()))
		call_out("attack",3,this_player(),1);
}

int attack(object me,int count)
{
	object muren;
	muren= new(__DIR__"npc/bronzefighter");
	muren->move(this_object());
	if (environment(me)!=this_object())
		return 1;
	message_vision("һ��ͭ����$N������",me);
	muren->do_perform(me,count);
	me->set_temp("last_damage_from","˽̽����ͭ�˿ӣ����ڲ��⡣");
	if(present(me,this_object()) && count < 10){
		destruct(muren);
		count++;
		message_vision("ͭ�˻������˵�һ�ԣ�����\n",me);
		call_out("attack",1+random(2),me,count);
	}
	else	{
		destruct(muren);
		message_vision("\nһ��һ������ͭ�ź����򿪣�����\n\n",me);
		set("exits/west", __DIR__"kuoran");
		set("exits/east", __DIR__"gaoroom");
		me->delete_temp("last_damage_from");
	}
}

