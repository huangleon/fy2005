// silencer@fy4 workgroup 


inherit VRM_SERVER;

void create()
{
	// �Թ��������̳е�����ĵ������ơ�
	set_inherit_room(__DIR__"jq1-room");

	//�Թ��ĳ��Ϳ� (5-100)
	set_maze_long(14,14);
	
	//�趨�Թ���λ�����
	set_maze_spacing(5);

	//�Թ��������npc.
	//note: this one is optional
//	set_maze_npcs(__DIR__"npc/w-sentry-1");

	//�Թ������ڷ��� npc �Ŀ�����(1-100)
	//note: this one is optional too, if not set, then default is 20 (1/5)
//	set_maze_npc_rate(100);

	//�Թ��ؽ�ʱ�� pass in integer ����Ϊ��λ
	//note: this one is optional, if not set then default is no refresh
	//if pass in 0, then means no refresh too.
	// this example means maze will be refreshed in 1 hour.
//	set_maze_refresh(7200);

	//��ڷ���(�����ڶ���)
	set_entry_dir("west");

	//�������������ӷ���
	set_link_entry_dir("west");

	//�������������ӵ�����
	set_link_entry_room(__DIR__"jq1-entry");
	
	//��ڵ�����(��������link_entry_room���Ǹ���ʵroom������
	set_link_entry_room_x(-30);
	set_link_entry_room_y(-15);
	set_link_entry_room_z(-10);
	

	//��������������ӷ���
	set_link_exit_dir("east");

	//��������������ӵ�����
	set_link_exit_room(__DIR__"jq1-exit");

	//��ڷ��������
	set_entry_short("������");

	//��ڷ�������
	set_entry_desc(@LONG
�Ϲ��뾣�������˾�����������֮�ˣ������ü�������ʱ��ǰ��ѵ����е��� 
����֮��������Ҳʱ�������������µ��������޴��Ͷ����Ǯ����������ø��� 
���������佲��������������ǰ�����ֱ�޷��������ﾹ�ڵ��£��ƻ��յ������� 
����磬��Բ����֮�������ͭ�Ÿߴ����ɡ�һ��˶��Ľ��ҿ������ɷ����һ 
�����䡱�֡�
LONG
);

	//���ڷ��������
	set_exit_short("��");

	//���ڷ�������
	set_exit_desc(@LONG
�������Թ���ĵ��ã������һ���������������Եľ�������ɭ�ϡ�ǰ���
�������ã�ԭ�����Ϲٽ��ÿ��һ�ε�����֮��������ǰ�Ϲ����˽��˴�ɨһ�£�
�����˼�����ݲ����Ŀ��ˡ�������
LONG
);

	//�Թ�����Ķ�����
	set_maze_room_short("ƶ����");

	//�Թ����������������ж�������������ÿ����
	//���ʱ���������ѡ��һ����
	set_maze_room_desc(@LONG
�Ϲ�����Ҿ�ƶ��������ĸ�����Ժ���ӣ������˼�����ƶ����������Ǯ��� 
Ϊ������һ�����İ�ᣬ���еļ����벻�ס���ʹ���ս�Ǯ�︻�ɵй����Ϲ�Ҳ�� 
�ſ���ɮ������������µ��ӽ��������������޷��������й���ƶ��һ�أ��� 
�������������ԻὫ�����ʦ�š�
LONG
);

	// �Թ������Ƿ�Ϊ���ⷿ�䣿
	set_outdoors(0);
}
