// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "��ˮ����");
        set("long", @LONG
����û�������е���ô�����Ժ�����Ŀ�����׵�һ�У����׳����˸�ɫ
��ɺ���ͱ�������������м���һ�������Ķ��壬���Ͼ�Ȼû��˿�����Σ��㲻
�ɵ�ת����������ߡ���Զ����һ��ʯ��������������ƴ���ĸ��֣�ˮ��֮�ţ���
LONG
        );
   	set("exits", ([ 
      		"enter" : __DIR__"gongnei",
      		"up" : __DIR__"lake",
   	]));
	set("coor/x",0);
	set("coor/y",-40);
	set("coor/z",10);
	set("underwater",50);
	set("water_damage",10);
	setup();
}

void init()
{
	object me;
	if (userp(me=this_player()))
		me->apply_condition("underwater",10);
}

/*
int do_air(object ob) 
{
   object *inv;
   int	i, da;

   	if (environment(ob)) == this_object()
   inv = all_inventory(this_object());
   if(sizeof(inv) == 0) return 1;
   for(i=0;i<sizeof(inv);i++) {
      if(userp(inv[i])) {
         tell_object(inv[i], "��ֻ�����ؿڷ��ƣ����ǿ���뿪����ɡ�\n");
         da = 50000 / (inv[i]->query("max_force")+1);
         if(da>100) da = 50;
         if(da<10) da = 10;
         inv[i]->receive_damage("kee", da); 
         inv[i]->set_temp("last_damage_from","�ڰ�ˮ�����������ˡ�\n");
      }
   }
   call_out("do_air", 5+random(10), this_object());
}
*/

